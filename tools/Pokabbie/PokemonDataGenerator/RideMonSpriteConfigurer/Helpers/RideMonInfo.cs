﻿using Newtonsoft.Json;
using PokemonDataGenerator.Utils;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RideMonSpriteConfigurer.Helpers
{

	public class SpeciesRideMonInfo
	{
		public struct SpriteInfo
		{
			public int MonOffsetX;
			public int MonOffsetY;
			public int RiderOffsetX;
			public int RiderOffsetY;
			public bool RiderRendersInFront;
		}

		[JsonIgnore]
		public string SpeciesName;

		public SpriteInfo UpSprite;
		public SpriteInfo DownSprite;
		public SpriteInfo SideSprite;
		public bool SupportsClimbing;
		public bool SupportsSwimming;
		public bool SupportsFlying;
	}

	public static class RideMonInfoHelper
	{
		private static readonly JsonSerializerSettings c_JsonSettings = new JsonSerializerSettings
		{
			Formatting = Formatting.Indented
		};

		private static readonly string c_SourceFilePath = Path.GetFullPath(@"..\..\mon_ride_info.json");

		private static Dictionary<string, SpeciesRideMonInfo> s_SpeciesToRideInfo = new Dictionary<string, SpeciesRideMonInfo>();

		static RideMonInfoHelper()
		{
			ImportSourceData();
		}

		public static void ImportSourceData()
		{
			if (File.Exists(c_SourceFilePath))
			{
				string jsonData = File.ReadAllText(c_SourceFilePath);

				s_SpeciesToRideInfo = JsonConvert.DeserializeObject<Dictionary<string, SpeciesRideMonInfo>>(jsonData, c_JsonSettings);
			}
		}

		public static void ExportSourceData()
		{
			string jsonData = JsonConvert.SerializeObject(s_SpeciesToRideInfo, c_JsonSettings);
			File.WriteAllText(c_SourceFilePath, jsonData);
		}

		public static void ExportGameData()
		{
			string fileName = Path.Combine(GameDataHelpers.RootDirectory, "src\\data\\rogue_ridemon_infos.h");

			Console.WriteLine($"Exporting to '{fileName}'");
			Directory.CreateDirectory(Path.GetDirectoryName(fileName));

			StringBuilder content = new StringBuilder();

			content.AppendLine("// == WARNING ==");
			content.AppendLine("// DO NOT EDIT THIS FILE");
			content.AppendLine("// This file was automatically generated by PokemonDataGenerator");
			content.AppendLine("//");
			content.AppendLine("");

			content.AppendLine("static const struct RideMonInfo sRideMonInfo[NUM_SPECIES] = \n{");
			
			foreach(var entry in s_SpeciesToRideInfo.Where(kvp => GameDataHelpers.SpeciesDefines.ContainsKey("SPECIES_" + kvp.Key)))
			{
				string species = entry.Key;
				var rideInfo = entry.Value;

				content.AppendLine($"\t[SPECIES_{species}] =");
				content.AppendLine($"\t{{");

				void PrintSpriteInfo(string name, SpeciesRideMonInfo.SpriteInfo spriteInfo)
				{
					int xFlip = 1;

					if (name == "RIDE_SPRITE_DIR_SIDE")
						xFlip = -1;

					content.AppendLine($"\t\t\t[{name}] =");
					content.AppendLine($"\t\t\t{{");
					content.AppendLine($"\t\t\t\t.playerX={spriteInfo.RiderOffsetX * xFlip}, .playerY={spriteInfo.RiderOffsetY},");
					content.AppendLine($"\t\t\t\t.monX={spriteInfo.MonOffsetX * xFlip}, .monY={spriteInfo.MonOffsetY},");
					content.AppendLine($"\t\t\t\t.playerRendersInFront={(spriteInfo.RiderRendersInFront ? "RIDER_SHOW_INFRONT" : "RIDER_SHOW_BEHIND")},");
					content.AppendLine($"\t\t\t}},");}

				// Flags
				content.Append("\t\t.flags = RIDE_MON_FLAG_CAN_RIDE");

				if (rideInfo.SupportsClimbing)
					content.Append(" | RIDE_MON_FLAG_CAN_CLIMB");

				if (rideInfo.SupportsSwimming)
					content.Append(" | RIDE_MON_FLAG_CAN_SWIM");

				if (rideInfo.SupportsFlying)
					content.Append(" | RIDE_MON_FLAG_CAN_FLY");

				content.AppendLine(",");

				// Sprite info
				content.AppendLine("\t\t.spriteInfo = ");
				content.AppendLine("\t\t{");

				PrintSpriteInfo("RIDE_SPRITE_DIR_UP", rideInfo.UpSprite);
				PrintSpriteInfo("RIDE_SPRITE_DIR_DOWN", rideInfo.DownSprite);
				PrintSpriteInfo("RIDE_SPRITE_DIR_SIDE", rideInfo.SideSprite);

				content.AppendLine("\t\t}");

				content.AppendLine("\t},");
			}

			content.AppendLine("};");

			string fullStr = content.ToString().Replace("\t", "    ");
			File.WriteAllText(fileName, fullStr);
		}

		public static SpeciesRideMonInfo FindRideInfo(string species)
		{
			string internalName = GameDataHelpers.FormatKeyword(species);

			if (s_SpeciesToRideInfo.TryGetValue(internalName, out SpeciesRideMonInfo info))
			{
				info.SpeciesName = internalName;
				return info;
			}

			return null;
		}

		public static SpeciesRideMonInfo TryCreateRideInfo(string species)
		{
			string internalName = GameDataHelpers.FormatKeyword(species);

			if (GameDataHelpers.SpeciesDefines.ContainsKey("SPECIES_" + internalName) && !s_SpeciesToRideInfo.ContainsKey(internalName))
			{
				SpeciesRideMonInfo info = new SpeciesRideMonInfo();
				info.SpeciesName = internalName;


				string monOverworldSprite = Path.Combine(GameDataHelpers.RootDirectory, "graphics\\object_events\\pics\\pokemon_ow\\" + internalName + ".png");
				Image monSourceImg = Image.FromFile(monOverworldSprite);

				if (monSourceImg.Height >= 64)
				{
					// Auto offset large sprite
					info.DownSprite.MonOffsetY -= 16;
					info.SideSprite.MonOffsetY -= 16;
					info.UpSprite.MonOffsetY -= 16;
				}

				s_SpeciesToRideInfo.Add(internalName, info);

				return info;
			}

			return null;
		}

		public static bool DeleteRideInfo(string species)
		{
			string internalName = GameDataHelpers.FormatKeyword(species);

			if (s_SpeciesToRideInfo.ContainsKey(internalName))
			{
				s_SpeciesToRideInfo.Remove(internalName);
				return true;
			}

			return false;
		}

		public static string GetRelativeSpeciesName(string fromSpecies, int delta, bool filterRideable)
		{
			string lookupName = "SPECIES_" + GameDataHelpers.FormatKeyword(fromSpecies);

			while (true)
			{
				var kvpList = GameDataHelpers.SpeciesDefines.ToList();

				int index = kvpList.FindIndex((kvp) => kvp.Key == lookupName);

				if (index != -1)
				{
					index += delta;

					if (delta < 0)
					{
						while (index < 0)
							index += kvpList.Count;
					}

					index %= kvpList.Count;
				}

				string speciesKey = kvpList[0].Key;

				if (index >= 0 && index < kvpList.Count)
				{
					speciesKey = kvpList[index].Key;
				}

				string speciesSuffix = speciesKey.Substring("SPECIES_".Length);

				if (filterRideable && FindRideInfo(speciesSuffix) == null)
				{
					// Keep going
					lookupName = speciesKey;
					continue;
				}

				return speciesSuffix;
			}
		}

		public static Bitmap CreateRidingSprite(Image riderSource, int riderIdx, Image monSource, int monIdx, SpeciesRideMonInfo.SpriteInfo spriteInfo)
		{
			Bitmap riderBitmap = new Bitmap(riderSource);
			Bitmap monBitmap = new Bitmap(monSource);

			int monFrameWidth = monSource.Width / 6;
			int monFrameHeight = monSource.Height;
			Color monTransparent = monBitmap.GetPixel(0, 0);

			int riderFrameWidth = riderSource.Width / 9;
			int riderFrameHeight = riderSource.Height;
			Color riderTransparent = riderBitmap.GetPixel(0, 0);

			Bitmap output = new Bitmap(monFrameWidth, monFrameHeight);

			// Transparent fill
			for (int y = 0; y < monFrameHeight; ++y)
			{
				for (int x = 0; x < monFrameWidth; ++x)
				{
					output.SetPixel(x, y, monTransparent);
				}
			}

			void RenderMon()
			{
				// Place mon
				for (int y = 0; y < monFrameHeight; ++y)
				{
					for (int x = 0; x < monFrameWidth; ++x)
					{
						Color col = monBitmap.GetPixel(x + monIdx * monFrameWidth, y);

						int writeX = x + spriteInfo.MonOffsetX;
						int writeY = y + spriteInfo.MonOffsetY;

						if (col != monTransparent && writeX >= 0 && writeX < output.Width && writeY >= 0 && writeY < output.Height)
							output.SetPixel(writeX, writeY, col);
					}
				}
			}

			void RenderRider()
			{
				// Place rider
				int baseOffsetX = monFrameWidth / 2 - riderFrameWidth / 2;
				int baseOffsetY = (monFrameHeight - riderFrameHeight) / 2;

				for (int y = 0; y < riderFrameHeight; ++y)
				{
					for (int x = 0; x < riderFrameWidth; ++x)
					{
						Color col = riderBitmap.GetPixel(x + riderIdx * riderFrameWidth, y);

						int writeX = x + spriteInfo.RiderOffsetX + baseOffsetX;
						int writeY = y + spriteInfo.RiderOffsetY + baseOffsetY;

						if (col != riderTransparent && writeX >= 0 && writeX < output.Width && writeY >= 0 && writeY < output.Height)
							output.SetPixel(writeX, writeY, col);
					}
				}
			}

			if (spriteInfo.RiderRendersInFront)
			{
				RenderMon();
				RenderRider();
			}
			else
			{
				RenderRider();
				RenderMon();
			}

			return output;
		}
	}
}
