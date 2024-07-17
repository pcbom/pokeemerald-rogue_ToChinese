

// When changing this, make sure to:
// -bump ROGUE_SAVE_VERSION in rogue_save.c
// -update SAVE_VER_ID_X_Y_Z enum in rogue_save.h
// -update RogueSave_GetVersionIdFor()
const u8 gText_RogueVersion[] = _("v2.0.1a");

#ifdef ROGUE_EXPANSION
const u8 gText_RogueVersionPrefix[] = _("EX");
#else
const u8 gText_RogueVersionPrefix[] = _("Vanilla");
#endif

#if defined(ROGUE_FEATURE_AUTOMATION)
const u8 gText_RogueVersionSuffix[] = _("(AUTOMATION)");
#elif defined(ROGUE_DEBUG)
const u8 gText_RogueVersionSpacer[] = _(" - ");
const u8 gText_RogueVersionSuffix[] = _("(DEBUG)");
#else
const u8 gText_RogueVersionSpacer[] = _("");
const u8 gText_RogueVersionSuffix[] = _(""); // no subtitle for 2.0
#endif

// UI String
//
const u8 gText_StatusRoute[] = _("路线: {STR_VAR_1}\n");
const u8 gText_StatusBadges[] = _("徽章: {STR_VAR_1}\n");
const u8 gText_StatusScore[] = _("分数: {STR_VAR_1}\n");
const u8 gText_StatusTimer[] = _("时长: {STR_VAR_1}:{STR_VAR_2}\n");
const u8 gText_StatusClock[] = _("{STR_VAR_1}:{STR_VAR_2}\n");
const u8 gText_StatusSeasonSpring[] = _("春");
const u8 gText_StatusSeasonSummer[] = _("夏");
const u8 gText_StatusSeasonAutumn[] = _("秋");
const u8 gText_StatusSeasonWinter[] = _("冬");

// Colours aren't exact as they'll be used in battle UI
const u8 gText_MoveEffective[] = _("{COLOR BLUE}{SHADOW DYNAMIC_COLOR6}Neutral");
const u8 gText_MoveNoEffect[] = _("{COLOR TRANSPARENT}{SHADOW BLUE}No Effect…");
const u8 gText_MoveSuperEffective[] = _("{COLOR GREEN}{SHADOW DYNAMIC_COLOR6}Effective!");
const u8 gText_MoveNotVeryEffective[] = _("{COLOR WHITE}{SHADOW DYNAMIC_COLOR6}Not Effective");
const u8 gText_MoveSlash[] = _("{COLOR BLUE}{SHADOW DYNAMIC_COLOR6}·");
const u8 gText_MoveShortEffective[] = _("{COLOR BLUE}{SHADOW DYNAMIC_COLOR6}Neutrl");
const u8 gText_MoveShortNoEffect[] = _("{COLOR TRANSPARENT}{SHADOW BLUE}No Efct");
const u8 gText_MoveShortSuperEffective[] = _("{COLOR GREEN}{SHADOW DYNAMIC_COLOR6}Effect");
const u8 gText_MoveShortNotVeryEffective[] = _("{COLOR WHITE}{SHADOW DYNAMIC_COLOR6}NtEfct");


// Trainers
//
const u8 gText_TrainerName_Default[] = _("贝尔");

const u8 gText_TrainerName_Brendan[] = _("小悠");
const u8 gText_TrainerName_May[] = _("小遥");
const u8 gText_TrainerName_Red[] = _("赤");
const u8 gText_TrainerName_Leaf[] = _("叶子");
const u8 gText_TrainerName_Ethan[] = _("阿响");
const u8 gText_TrainerName_Lyra[] = _("琴音");

// Items
//
const u8 gText_EscapeRopeDesc[] = _(
    "Use to escape\n"
    "instantly from\n"
    "most encounters.");

// Difficulty/Config lab settings
//

//{COLOR DARK_GRAY}{SHADOW DARK_GRAY} <default> orange tint
//{COLOR GREEN}{SHADOW LIGHT_GREEN} no tint
//{COLOR RED}{SHADOW LIGHT_RED} red tint
//{COLOR LIGHT_BLUE}{SHADOW BLUE} green tint
const u8 gText_16Spaces[] = _("                ");
const u8 gText_32Spaces[] = _("                                ");

const u8 gText_DifficultySettings[] = _("难度设置");
const u8 gText_DifficultyArrowLeft[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}{LEFT_ARROW}");
const u8 gText_DifficultyArrowRight[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}{RIGHT_ARROW}");

const u8 gText_DifficultyDoesntAffectReward[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}(rewards unaffected)");
const u8 gText_DifficultyRewardLevel[] = _("{FONT_SMALL}{COLOR GREEN}{SHADOW LIGHT_GREEN}通关等级: ");

const u8 gText_DifficultyPreset[] = _("难度");

// Colours on the Settings Screen are out of order and wild
//LIGHT_BLUE = green
//BLUE = light green
//LIGHT_RED = red
//RED = light red
//DARK_GRAY = light yellow
//LIGHT_GRAY = dark yellow
//LIGHT_GREEN = light grey
const u8 gText_DifficultyPresetEasy[] = _("{COLOR LIGHT_BLUE}{SHADOW BLUE}简单");
const u8 gText_DifficultyPresetMedium[] = _("{COLOR LIGHT_BLUE}{SHADOW LIGHT_GREEN}正常");
const u8 gText_DifficultyPresetHard[] = _("{COLOR LIGHT_RED}{SHADOW LIGHT_GREEN}困难");
const u8 gText_DifficultyPresetBrutal[] = _("{COLOR LIGHT_RED}{SHADOW RED}狂暴");
const u8 gText_DifficultyPresetCustom[] = _("{COLOR DARK_GRAY}{SHADOW LIGHT_GREEN}自定义");

const u8 gText_DifficultyEnabled[] = _("{COLOR LIGHT_BLUE}{SHADOW BLUE}开启  ");
const u8 gText_DifficultyDisabled[] = _("{COLOR LIGHT_RED}{SHADOW LIGHT_GREEN}关闭");
const u8 gText_DifficultyModeActive[] = _("{COLOR LIGHT_BLUE}{SHADOW BLUE}Active!");

const u8 gText_DifficultyExpAll[] = _("全队经验");
const u8 gText_DifficultyOverLvl[] = _("无等级限制");
const u8 gText_DifficultyEVGain[] = _("获得努力值");
const u8 gText_DifficultyOverworldMons[] = _("宝可梦明雷");
const u8 gText_DifficultyBagWipe[] = _("白手起家");
const u8 gText_DifficultySwitchMode[] = _("换人模式");

const u8 gText_DifficultyTrainers[] = _("训练师");
const u8 gText_DifficultyItems[] = _("Items");
const u8 gText_DifficultyLegendaries[] = _("Legendaries");

const u8 gText_DifficultyCustomDesc[] = _(
    "{COLOR GREEN}{SHADOW LIGHT_GREEN}"
    "自定义操作设置并调整难度,\n"
    "打造你的专属游戏体验."
);

const u8 gText_AdventureCustomDesc[] = _(
    "{COLOR GREEN}{SHADOW LIGHT_GREEN}"
    "自定义操作设置并调整难度,\n"
    "打造你的专属游戏体验."
);

const u8 gText_DifficultyTrainersDesc[] = _(
    "{COLOR GREEN}{SHADOW LIGHT_GREEN}"
    "该选项用来调整其他训练师\n"
    "所携带宝可梦的质量、数量和强度."
);

const u8 gText_DifficultyItemsDesc[] = _(
    "{COLOR GREEN}{SHADOW LIGHT_GREEN}"
    "TODO. This needs a rework..."
);

const u8 gText_DifficultyLegendariesDesc[] = _(
    "{COLOR GREEN}{SHADOW LIGHT_GREEN}"
    "Decreases quality and quantity of\n"
    "Legendary {PKMN} encounters."
);

// Campaigns
//
const u8 gText_CampaignHofTitle[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}{STR_VAR_1}");

const u8 gText_Campaign_None[] = _("???");
const u8 gText_Campaign_LowBST[] = _("BST CUP");
const u8 gText_Campaign_Classic[] = _("Classic Mode");
const u8 gText_Campaign_MiniBossBattler[] = _("Battle Addict");
const u8 gText_Campaign_AutoBattler[] = _("Auto Battler");
const u8 gText_Campaign_LaterManner[] = _("LaterManner Mode");
const u8 gText_Campaign_PokeballLimit[] = _("Limited Capture");
const u8 gText_Campaign_OneHp[] = _("One Hit Mode");

// Debug
//
#ifdef ROGUE_DEBUG
const u8 gText_RogueDebug_Header[] = _("ROGUE DEBUG");
const u8 gText_RogueDebug_Save[] = _("\nSave: ");
const u8 gText_RogueDebug_Room[] = _("\nRoom: ");
const u8 gText_RogueDebug_BossRoom[] = _("\nBossRoom: ");
const u8 gText_RogueDebug_Difficulty[] = _("\nDfcy: ");
const u8 gText_RogueDebug_PlayerLvl[] = _("\nPly lvl: ");
const u8 gText_RogueDebug_WildLvl[] = _("\nWld lvl: ");
const u8 gText_RogueDebug_WildCount[] = _("\nWld Opt: ");
const u8 gText_RogueDebug_ItemCount[] = _("\nItm Opt: ");
const u8 gText_RogueDebug_TrainerCount[] = _("\nTrn Opt: ");
const u8 gText_RogueDebug_Seed[] = _("\nSeed: ");

const u8 gText_RogueDebug_AdvHeader[] = _("ROGUE ADVPATH");
const u8 gText_RogueDebug_AdvCount[] = _("\nCount: ");
const u8 gText_RogueDebug_X[] = _("\nX: ");
const u8 gText_RogueDebug_Y[] = _("\nY: ");
#endif
