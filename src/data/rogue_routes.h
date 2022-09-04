
#include "constants/event_objects.h"
#include "constants/layouts.h"
#include "constants/maps.h"

#define ROUTE_MAP(map) { .layout=LAYOUT_##map, .group=MAP_GROUP(map), .num=MAP_NUM(map), }
#define ENCOUNTER_MAP(id, map) { .encounterId=id, .layout=LAYOUT_##map, .group=MAP_GROUP(map), .num=MAP_NUM(map), }

const struct RogueRouteData gRogueRouteTable[ROGUE_ROUTE_COUNT] = {
    {
        .map = ROUTE_MAP(ROGUE_ROUTE_FIELD0),
        .wildTypeTable = { TYPE_GRASS, TYPE_NORMAL, TYPE_FLYING }
    },
    {
        .map = ROUTE_MAP(ROGUE_ROUTE_FIELD1),
        .wildTypeTable = { TYPE_ELECTRIC, TYPE_STEEL, TYPE_ICE }
    },
    {
        .dropRarity = 1,
        .map = ROUTE_MAP(ROGUE_ROUTE_FOREST0),
        .wildTypeTable = { TYPE_BUG, TYPE_GHOST, TYPE_POISON }
    },
    {
        .dropRarity = 2,
        .map = ROUTE_MAP(ROGUE_ROUTE_CAVE0),
        .wildTypeTable = { TYPE_ROCK, TYPE_ICE, TYPE_DRAGON }
    },
    {
        .map = ROUTE_MAP(ROGUE_ROUTE_MOUNTAIN0),
        .wildTypeTable = { TYPE_GROUND, TYPE_FIRE, TYPE_FIGHTING }
    },
    {
        .map = ROUTE_MAP(ROGUE_ROUTE_MOUNTAIN1),
#ifdef ROGUE_EXPANSION
        .wildTypeTable = { TYPE_FAIRY, TYPE_DARK, TYPE_PSYCHIC }
#else
        .wildTypeTable = { TYPE_FIGHTING, TYPE_DARK, TYPE_PSYCHIC }
#endif
    },
    {
        .map = ROUTE_MAP(ROGUE_ROUTE_MOUNTAIN2),
        .wildTypeTable = { TYPE_GROUND, TYPE_GHOST, TYPE_FIRE }
    },
    {
        .map = ROUTE_MAP(ROGUE_ROUTE_MOUNTAIN3),
        .wildTypeTable = { TYPE_ROCK, TYPE_DRAGON, TYPE_POISON }
    },
    {
        .map = ROUTE_MAP(ROGUE_ROUTE_WATER_FRONT0),
        .wildTypeTable = { TYPE_WATER, TYPE_FLYING, TYPE_GRASS }
    },
    {
        .map = ROUTE_MAP(ROGUE_ROUTE_WATER_FRONT1),
        .wildTypeTable = { TYPE_NORMAL, TYPE_FIGHTING, TYPE_DARK }
    },
    {
        .map = ROUTE_MAP(ROGUE_ROUTE_URBAN0),
        .wildTypeTable = { TYPE_STEEL, TYPE_ELECTRIC, TYPE_PSYCHIC }
    },
    {
        .map = ROUTE_MAP(ROGUE_ROUTE_URBAN1),
#ifdef ROGUE_EXPANSION
        .wildTypeTable = { TYPE_FAIRY, TYPE_ICE, TYPE_BUG }
#else
        .wildTypeTable = { TYPE_WATER, TYPE_ICE, TYPE_BUG }
#endif
    }
};

static const struct RogueEncounterMap sRouteMapsSpecial[] = 
{
    ENCOUNTER_MAP(SPECIES_ARTICUNO, ROGUE_SPECIAL_ARTICUNO),
    ENCOUNTER_MAP(SPECIES_ZAPDOS, ROGUE_SPECIAL_ZAPDOS),
    ENCOUNTER_MAP(SPECIES_MOLTRES, ROGUE_SPECIAL_MOLTRES),
    
    ENCOUNTER_MAP(SPECIES_MEWTWO, ROGUE_SPECIAL_MEWTWO),
    ENCOUNTER_MAP(SPECIES_MEW, FARAWAY_ISLAND_INTERIOR),

    ENCOUNTER_MAP(SPECIES_RAIKOU, ROGUE_SPECIAL_RAIKOU),
    ENCOUNTER_MAP(SPECIES_ENTEI, ROGUE_SPECIAL_ENTEI),
    ENCOUNTER_MAP(SPECIES_SUICUNE, ROGUE_SPECIAL_SUICUNE),

    ENCOUNTER_MAP(SPECIES_HO_OH, NAVEL_ROCK_TOP),
    ENCOUNTER_MAP(SPECIES_LUGIA, NAVEL_ROCK_BOTTOM),

    ENCOUNTER_MAP(SPECIES_CELEBI, ROGUE_SPECIAL_CELEBI),

    ENCOUNTER_MAP(SPECIES_REGICE, ISLAND_CAVE),
    ENCOUNTER_MAP(SPECIES_REGIROCK, DESERT_RUINS),
    ENCOUNTER_MAP(SPECIES_REGISTEEL, ANCIENT_TOMB),

    ENCOUNTER_MAP(SPECIES_GROUDON, TERRA_CAVE_END),
    ENCOUNTER_MAP(SPECIES_KYOGRE, MARINE_CAVE_END),
    ENCOUNTER_MAP(SPECIES_RAYQUAZA, SKY_PILLAR_TOP),

    ENCOUNTER_MAP(SPECIES_LATIAS, ROGUE_SOUTHERN_ISLAND_LATIAS),
    ENCOUNTER_MAP(SPECIES_LATIOS, ROGUE_SOUTHERN_ISLAND_LATIOS),

    ENCOUNTER_MAP(SPECIES_JIRACHI, ROGUE_SPECIAL_JIRACHI),
    ENCOUNTER_MAP(SPECIES_DEOXYS, BIRTH_ISLAND_EXTERIOR),

#ifdef ROGUE_EXPANSION
    ENCOUNTER_MAP(SPECIES_UXIE, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_MESPRIT, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_AZELF, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_DIALGA, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_PALKIA, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_HEATRAN, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_REGIGIGAS, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_GIRATINA, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_CRESSELIA, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_PHIONE, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_MANAPHY, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_DARKRAI, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_SHAYMIN, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_ARCEUS, ROGUE_SPECIAL_GENERIC_WILD_MON),

    ENCOUNTER_MAP(SPECIES_VICTINI, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_COBALION, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_TERRAKION, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_VIRIZION, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_TORNADUS, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_THUNDURUS, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_RESHIRAM, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_ZEKROM, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_LANDORUS, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_KYUREM, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_KELDEO, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_MELOETTA, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_GENESECT, ROGUE_SPECIAL_GENERIC_WILD_MON),

    ENCOUNTER_MAP(SPECIES_XERNEAS, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_YVELTAL, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_ZYGARDE, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_DIANCIE, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_HOOPA, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_VOLCANION, ROGUE_SPECIAL_GENERIC_WILD_MON),

    //ENCOUNTER_MAP(SPECIES_TYPE_NULL),
    ENCOUNTER_MAP(SPECIES_SILVALLY, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_TAPU_KOKO, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_TAPU_LELE, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_TAPU_BULU, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_TAPU_FINI, ROGUE_SPECIAL_GENERIC_WILD_MON),
    //ENCOUNTER_MAP(SPECIES_COSMOG),
    //ENCOUNTER_MAP(SPECIES_COSMOEM),
    ENCOUNTER_MAP(SPECIES_SOLGALEO, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_LUNALA, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_NIHILEGO, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_BUZZWOLE, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_PHEROMOSA, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_XURKITREE, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_CELESTEELA, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_KARTANA, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_GUZZLORD, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_NECROZMA, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_MAGEARNA, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_MARSHADOW, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_POIPOLE, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_NAGANADEL, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_STAKATAKA, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_BLACEPHALON, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_ZERAORA, ROGUE_SPECIAL_GENERIC_WILD_MON),
    //ENCOUNTER_MAP(SPECIES_MELTAN, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_MELMETAL, ROGUE_SPECIAL_GENERIC_WILD_MON),

    ENCOUNTER_MAP(SPECIES_ZACIAN, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_ZAMAZENTA, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_ETERNATUS, ROGUE_SPECIAL_GENERIC_WILD_MON),
    //ENCOUNTER_MAP(SPECIES_KUBFU, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_URSHIFU, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_ZARUDE, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_REGIELEKI, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_REGIDRAGO, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_GLASTRIER, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_SPECTRIER, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_CALYREX, ROGUE_SPECIAL_GENERIC_WILD_MON),
    
    // Forms
    ENCOUNTER_MAP(SPECIES_KYUREM_WHITE, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_KYUREM_BLACK, ROGUE_SPECIAL_GENERIC_WILD_MON),

    ENCOUNTER_MAP(SPECIES_NECROZMA_DUSK_MANE, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_NECROZMA_DAWN_WINGS, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_NECROZMA_ULTRA, ROGUE_SPECIAL_GENERIC_WILD_MON),
    
    ENCOUNTER_MAP(SPECIES_URSHIFU_RAPID_STRIKE_STYLE, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_CALYREX_ICE_RIDER, ROGUE_SPECIAL_GENERIC_WILD_MON),
    ENCOUNTER_MAP(SPECIES_CALYREX_SHADOW_RIDER, ROGUE_SPECIAL_GENERIC_WILD_MON),
#endif
};

const struct RogueEncounterData gRogueLegendaryEncounterInfo = 
{
    .mapCount = ARRAY_COUNT(sRouteMapsSpecial),
    .mapTable = sRouteMapsSpecial
};

static const struct RogueEncounterMap sRouteMapsRestStop[] = 
{
    ENCOUNTER_MAP(OBJ_EVENT_GFX_NURSE, ROGUE_ENCOUNTER_REST_STOP),
    ENCOUNTER_MAP(OBJ_EVENT_GFX_MART_EMPLOYEE, ROGUE_ENCOUNTER_SHOPS),
    ENCOUNTER_MAP(OBJ_EVENT_GFX_MYSTERY_GIFT_MAN, ROGUE_ENCOUNTER_TUTORS),
};

const struct RogueEncounterData gRogueRestStopEncounterInfo = 
{
    .mapCount = ARRAY_COUNT(sRouteMapsRestStop),
    .mapTable = sRouteMapsRestStop
};


static const struct RogueEncounterMap sRouteMiniBossEncounters[] = 
{
    ENCOUNTER_MAP(OBJ_EVENT_GFX_MAXIE, ROGUE_ENCOUNTER_MINI_BOSS),
    ENCOUNTER_MAP(OBJ_EVENT_GFX_ARCHIE, ROGUE_ENCOUNTER_MINI_BOSS),
    ENCOUNTER_MAP(OBJ_EVENT_GFX_WALLY, ROGUE_ENCOUNTER_MINI_BOSS),
    ENCOUNTER_MAP(OBJ_EVENT_GFX_BRENDAN_NORMAL, ROGUE_ENCOUNTER_MINI_BOSS) // Copy party
};

const struct RogueEncounterData gRouteMiniBossEncounters = 
{
    .mapCount = ARRAY_COUNT(sRouteMiniBossEncounters),
    .mapTable = sRouteMiniBossEncounters
};