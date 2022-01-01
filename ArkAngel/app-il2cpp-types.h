#pragma once
#include "Framework.h"
#include "Transform.h"
#include <string>
#include <vector>

struct DateTime
{
	unsigned long long dateData;
};


struct Color
{
	float r;
	float g;
	float b;
	float a;
};
struct Color32
{
	int rgba;
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;
};
enum class PortalAnimationType
{

};
struct ReviveKey
{
	Vector2i pos;
	int type;
};
struct HueSaturationBrightnessTint
{
	int hue;
	int saturation;
	int brightness;
	float tintR;
	float tintG;
	float tintB;
	float tintA;
	Color32 baseColor;
	float baseColorMultiplier;
	Color tintColor;
};
struct ACTkByte4
{
	unsigned char b1;
	unsigned char b2;
	unsigned char b3;
	unsigned char b4;
};
struct ObscuredFloat
{
	int currentCryptoKey;
	int hiddenValue;
	ACTkByte4 hiddenValueOldByte4;
	bool inited;
	float fakeValue;
	bool fakeValueActive;

	float get()
	{
		int decv = hiddenValue ^ currentCryptoKey;
		return *(float*)&decv;
	}
	void set(float v)
	{
		hiddenValue = (*(int*)&v) ^ currentCryptoKey;
	}
};
struct ObscuredInt
{
	int currentCryptoKey;
	int hiddenValue;
	bool inited;
	int fakeValue;
	bool fakeValueActive;
	int get()
	{
		return hiddenValue ^ currentCryptoKey;
	}
	void set(int v)
	{
		hiddenValue = v ^ currentCryptoKey;
	}
};
enum class CardVariant
{

};
struct CollectionCardData
{
	CardVariant variant;
	unsigned char count;
	int cardType;
};
struct InventoryKey
{
	int blockType;
	unsigned char itemType;

};
enum class ClanMemberRank
{
	None,
	Rookie,
	Member,
	Veteran,
	Elder,
	CoLeader,
	Leader,
};
enum class CameraZoomLevel
{
	ExtraFar,
	Far,
	Normal,
	Near,
};
enum class WorldType
{
	Default,
	Tutorial,
	DailyBonus,
	Igor,
	HalloweenTower,
	NetherWorld,
	LeprechaunCave,
	SummerQuest,
	DailyQuest,
	DeepNether,
	PixelStation,
	SecretBaseLaboratory,
	SuperHero,
	Tutorial2,
	LoreWorld,
	LoreWorldPublic,
	PixelMines,
	GeneratedMine,
	Hangar,
	JetRace,
	Fishing101,
	Lounge,
};
enum class AdminStatus
{
	AdminStatus_None,
	AdminStatus_Moderator,
	AdminStatus_Admin,
	AdminStatus_Influencer,
};
enum class CardBacks
{
	Basic,
	Special01,
	END_OF_ENUM,
};
enum class PlayerCostumeType
{
	None,
	Werewolf,
};
enum class TutorialState
{
	NotStarted,
	CharacterCreation,
	TutorialWorld,
	TutorialCompleted,
	TutorialPhase1,
	TutorialPhase2,
	TutorialPhase3,
	TutorialPhase4,
};
struct PlayerData
{
	Il2CppClass* klass;
	MonitorData* monitor;
	CameraZoomLevel cameraZoomLevel;
	float cameraZoomValue;
	ObscuredInt pendingBC;
	ObscuredInt bc;
	ObscuredInt gems;
	Il2CppObject* worldClientSpecialData;
	bool isPlayerBanned;
	short countryCode;
	DateTime banEndDate;
	Il2CppString* banUniversalReason;
	Il2CppString* banState;
	Il2CppList<int>* expressionSelectedList;
	DateTime accountAge;
	DateTime vipEndTime;
	int gender;
	Il2CppString* playerId;
	DateTime timeWhenPlayerCanDoNextPlaceBlock;
	DateTime timeWhenPlayerCanDoNextHit;
	DateTime nextClanGemBonusGiveAwayClaimTime;
	DateTime nextDailyBonusGiveAwayClaimTime;
	DateTime lastNormalDailyBonusClaimTime;
	DateTime nextNormalDailyBonusClaimTime;
	DateTime lastVIPDailyBonusClaimTime;
	DateTime nextVIPDailyBonusClaimTime;
	DateTime nextDailyAdsRefreshTime;
	DateTime nextDailyPvpRewardsRefreshTime;
	DateTime lastFreePrizeClaimTime;
	DateTime nextWelcomeGiftClaimTime;
	DateTime worldTimeLimitEndTimestamp;
	bool hasClaimedAdditionalAdBasedDailyBonus;
	bool isReadyToWatchDailyBonusAd;
	Il2CppList<int>* statisticsList;
	int nameChangeCounter;
	int playerBuffType;
	int lastLevelClaim;
	int passiveEffects;
	DateTime playerBuffEndTime;
	Il2CppList<int>* activePerks;
	Il2CppList<Il2CppObject*>* limitedOffersAvailable;
	Il2CppList<Il2CppObject*>* limitedOffersUsed;
	bool starterOffersPending;
	long long lastRotatingLimitedOfferTicks;
	int lastRotatingLimitedOfferIndex;
	Il2CppList<int>* ftueSoldItemIDs;
	int dailyAdsWatched;
	int dailyGemAdsWatched;
	int dailyAdTVAdsWatched;
	int pweAdSlotsUnlocked;
	int pweOrderAdSlotsUnlocked;
	int dailyPvpRewards;
	int fishingTournamentClaimPending;
	long long fishingTournamentPendingCupEndTicks;
	long long currentFishingCupRules;
	int fishingCupEntryEndTimeEpoch;
	int jetRaceDailyRunsCount;
	int jetRaceRunsCount;
	Il2CppArrayT<Il2CppObject*>* lastRandomizedBestSets;
	Il2CppObject* lastKnownBestSetWinner;
	int bestSetDailyVotesCount;
	int bestSetTotalVotesCount;
	long long bestSetLastVoteTimeTicks;
	Il2CppObject* myBestSetEntry;
	int skinColorIndex;
	int skinColorIndexBeforeOverride;
	int defaultFaceAnimationIndex;
	Il2CppString* reasonForWarning;
	Il2CppList<Il2CppObject*>* currentQuests;
	WorldType currentWorldType;
	bool showOnlineStatus;
	bool showLocation;
	bool isTrustedPlayer;
	bool modWantsToGoThroughDoors;
	bool adminWantsToGoThroughDoors;
	bool adminWantsToBeSummoned;
	bool adminWantsToEditWorld;
	bool adminWantsToGoGhostMode;
	bool adminIsIgnoringPortals;
	bool adminWantsToGoUndercoverMode;
	bool adminWantsToGoNoobMode;
	bool adminIsShowingKickBanInfo;
	bool modUsedTeleportDuringSession;
	Il2CppList<int>* boughtExpressions;
	Il2CppString* adminsNameOnUndercoverMode;
	Il2CppArrayT<Il2CppObject*>* dailyQuests;
	Il2CppArrayT<Il2CppObject*>* clanQuestsPersonal;
	Il2CppList<Il2CppString*>* previousThreeDailyQuestIds;
	Il2CppList<int>* previousClanQuestPersonalIds;
	Il2CppList<Il2CppString*>* alreadyBoughtOneTimeItems;
	Il2CppObject* onGoingTutorialQuest;
	Il2CppList<Il2CppObject*>* tutorialQuests;
	bool isTutorialQuestsCompleted;
	Il2CppDictionary* cardCollection;
	Il2CppDictionary* goldenCardCollection;
	Il2CppList<CollectionCardData>* basicDeck;
	Il2CppList<CollectionCardData>* advancedDeck;
	Il2CppList<int>* cardBacksUnlocked;
	int cardDustAmount;
	CardBacks selectedCardBack;
	int cardGameSkillLevel;
	int cardGameBasicDeckValue;
	int cardGameAdvancedDeckValue;
	long long cardSeasonStartTimestamp;
	int cardSeasonRating;
	int cardSeasonWinStreak;
	int cardSeasonBestLeagueThisSeason;
	bool cardGameFaceExpressionsEnabled;
	bool cardGameBodyExpressionsEnabled;
	AdminStatus playerAdminStatus;
	int petsAdventureEndTimeEpoch;
	Il2CppList<Il2CppString*>* favoriteWorldList;
	Il2CppList<int>* giftBoxesAccessed;
	Il2CppDictionary* vendorVersions;
	Il2CppDictionary* infoNPCVersions;
	int currentNewsVersion;
	int currentWotwVersion;
	Il2CppList<int>* itemsUnlocked;
	Il2CppList<int>* worldLoadArgs;
	Il2CppList<int>* genericVersioning;
	bool optedToTerms;
	Il2CppObject* expressionListLock;
	int familiarBlockType;
	Il2CppString* familiarName;
	bool isFamiliarMaxLevel;
	PlayerCostumeType playerCostumeType;
	DateTime playerCostumeEndTime;
	Il2CppArrayT<int>* hotSpotsBlockTypes;
	TutorialState tutorialState;
	Il2CppObject* instructionState;
	Il2CppObject* achievementState;
	int health;
	DateTime healTime;
	int amountHealedThisLife;
	int tempMaxHitPointsAdd;
	ClanMemberRank clanMemberRank;
	int clanFaction;
	Il2CppString* clanName;
	Il2CppString* clanTag;
	int clanId;
	int clanJoinTimeEpoch;
	int currentClanLevel;
	int clanMemberLevel;
	int clanMemberXP;
	int totalClanMemberXP;
	int totalClanMemberGems;
	int experienceAmount;
	int experienceLevel;
	int xpAmount;
	int xpLevel;
	short inventorySlots;
	Il2CppDictionary* inventory;
	Il2CppDictionary* inventoryData;
	InventoryKey beltItem1;
	void*/*IComparer`1*/ inventoryKeyComparer;
	short bankSlots;
	int deathCounter;
	DateTime raceStartTime;

};
struct Bounds
{
	Vector3 m_Center;
	Vector3 m_E;
};
struct RaycastHit2D
{
	Vector2 m_Centroid;
	Vector2 m_Point;
	Vector2 m_Normal;
	float m_Distance;
	float m_Fraction;
	int m_Collider;
};
struct CharacterRaycastOrigins
{
	Vector3 topLeft;
	Vector3 bottomRight;
	Vector3 bottomLeft;
};
struct ObscuredBool
{
	unsigned char currentCryptoKey;
	int hiddenValue;
	bool inited;
	bool fakeValue;
	bool fakeValueActive;
};
struct CharacterCollisionState2D
{
	Il2CppClass* klass;
	MonitorData* monitor;
	ObscuredBool right;
	ObscuredBool left;
	ObscuredBool above;
	ObscuredBool below;
	ObscuredBool becameGroundedThisFrame;
	ObscuredBool wasGroundedLastFrame;
	ObscuredBool movingDownSlope;
	ObscuredFloat slopeAngle;
};
struct AnimationCurve
{
	Il2CppClass* klass;
	MonitorData* monitor;
	void*/*IntPtr*/ m_Ptr;
};
struct LayerMask
{
	int m_Mask;
};
struct CharacterController2D
{
	Il2CppClass* klass;
	MonitorData* monitor;
	void*/*Action`1*/ onControllerCollidedEvent;
	void*/*Action`1*/ onTriggerEnterEvent;
	void*/*Action`1*/ onTriggerStayEvent;
	void*/*Action`1*/ onTriggerExitEvent;
	bool ignoreOneWayPlatformsThisFrame;
	float _skinWidth;
	LayerMask platformMask;
	LayerMask triggerMask;
	LayerMask oneWayPlatformMask;
	float slopeLimit;
	float jumpingThreshold;
	Il2CppObject* slopeSpeedMultiplier;
	int totalHorizontalRays;
	int totalVerticalRays;
	float _slopeLimitTangent;
	Il2CppObject* myTransform;
	Il2CppObject* boxCollider;
	Il2CppObject* rigidBody2D;
	Il2CppObject* collisionState;
	Vector3 velocity;
	CharacterRaycastOrigins _raycastOrigins;
	RaycastHit2D _raycastHit;
	Il2CppList<RaycastHit2D>* _raycastHitsThisFrame;
	float _verticalDistanceBetweenRays;
	float _horizontalDistanceBetweenRays;
	bool _isGoingUpSlope;
	Vector3 tempDeltaMovement;
	Bounds tempModifiedBounds;
	bool tempIsGoingRight;
	float tempRayDistance;
	Vector2 tempRayDirection;
	Vector3 tempInitialRayOrigin;
	Vector2 tempRay;
	Vector3 dodgeCornerMovement;
	bool tempIsGoingUp;
	LayerMask tempMask;
	bool tempDidFirstRayHit;
	bool tempDidLastRayHit;
	int tempIndex;
	bool tempDoCornerRayCheck;
	float tempInsideCorrection;
};
enum class NetherWorldEntryPoint
{
	
};
struct WorldItemBase
{
	Il2CppClass* klass;
	MonitorData* monitor;
	int itemId;
	int blockType;
	int blockDirection;
	bool isAnimationOn;
	bool useAnotherSprite;
	bool doDamageNow;
};
struct GuestBookData
{
	Il2CppClass* klass;
	MonitorData* monitor;
	int itemId;
	int blockType;
	int blockDirection;
	bool isAnimationOn;
	bool useAnotherSprite;
	bool doDamageNow;
	Il2CppList<Il2CppString*>* playerIds;
	Il2CppList<Il2CppString*>* messages;
	Il2CppList<long long>* timestamps;
	Il2CppList<int>* approved;
	int maxEntries;
	bool locked;
};
struct MannequinData
{
	Il2CppClass* klass;
	MonitorData* monitor;
	int itemId;
	int blockType;
	int blockDirection;
	bool isAnimationOn;
	bool useAnotherSprite;
	bool doDamageNow;
	Il2CppList<int>* itemsAsInventoryKeys;
	Il2CppList<Il2CppObject*>* inventoryDatas;
	int gender;
};
struct DisplayBlockData
{
	Il2CppClass* klass;
	MonitorData* monitor;
	int itemId;
	int blockType;
	int blockDirection;
	bool isAnimationOn;
	bool useAnotherSprite;
	bool doDamageNow;
	int storageItemAsInventoryKey;
	Il2CppObject* inventoryData;
	Il2CppString* text;
};
struct SafeData
{
	Il2CppClass* klass;
	MonitorData* monitor;
	int itemId;
	int blockType;
	int blockDirection;
	bool isAnimationOn;
	bool useAnotherSprite;
	bool doDamageNow;
	Il2CppList<int>* storageItemsAsInventoryKeys;
	Il2CppList<int>* storageItemsAmounts;
	int maxStorageItems;
	Il2CppList<Il2CppObject*>* inventoryDatas;
};
struct Player
{
	Il2CppClass* klass;
	MonitorData* monitor;
	uintptr_t mcp;
	Il2CppObject* myGameObject;
	Transform* myTransform;
	Il2CppObject* wrapper;
	Il2CppObject* wrapperDirectionScale;
	Il2CppObject* uiWrapper;
	Vector3 uiWrapperOriginalLocalPosition;
	PlayerData* myPlayerData;
	float isDeadTimeCounter;
	bool isLocalPlayer;
	bool allowedToResurrect;
	bool isDead;
	bool isResetDoneAfterDyingAnimation;
	bool isWaitingDeath;
	Il2CppObject* playerNameGameObject;
	Vector2i respawnMapPoint;
	bool isDoingMultitouchAction;
	float doMultitouchActionTimeCounter;
	float doMultitouchActionTime;
	int jumpMode;
	bool isContinuesJumpingActivated;
	bool wasPlayerInFogLastFrame;
	bool wasPlayerSwimmingLastFrame;
	bool isInFog;
	bool isSwimming;
	float velocityYDownAdvance;
	float mountFlyingJumpNormalHeightMultiplier60FPS;
	float mountFlyingJumpNormalHeightMultiplier;
	float animationSpeedPoisonedMultiplier;
	ObscuredFloat maxRocketJumpHeight;
	ObscuredFloat maxRocketVelocityY;
	ObscuredFloat minMountFlyingJumpHeight;
	ObscuredFloat maxMountFlyingJumpHeight;
	ObscuredFloat mountFlyingGravityMultiplier;
	ObscuredFloat maxMountFlyingVelocityY;
	ObscuredFloat normalizedHorizontalSpeed;
	ObscuredFloat lastNormalizedHorizontalSpeed;
	ObscuredFloat lastFrameVelocityY;
	ObscuredFloat maxXVelocity;
	ObscuredFloat maxFallVelocity;
	ObscuredFloat runSpeed;
	ObscuredFloat runSpeedPoisonedMultiplier;
	ObscuredFloat gravity;
	ObscuredFloat groundDamping;
	ObscuredFloat jumpNormalHeight;
	ObscuredFloat jumpHeight;
	ObscuredFloat rocketFuelConsumptionSpeed;
	ObscuredFloat inAirDamping;
	ObscuredFloat jumpMinHeight;
	ObscuredFloat rocketFuel;
	ObscuredFloat rocketFuelConsumptionSpeed60FPS;
	ObscuredFloat rocketHeightIncreaseSpeedFactor60FPS;
	ObscuredFloat rocketHeightReductionSpeedFactor60FPS;
	ObscuredFloat minRocketJumpHeight60FPS;
	ObscuredFloat maxRocketJumpHeight60FPS;
	ObscuredFloat mountFlyingHeightIncreaseSpeedFactor60FPS;
	ObscuredFloat mountFlyingHeightReductionSpeedFactor60FPS;
	ObscuredFloat minMountFlyingJumpHeight60FPS;
	ObscuredFloat maxMountFlyingJumpHeight60FPS;
	ObscuredFloat fullRocketFuel;
	ObscuredFloat rocketFuelRegenerationCooldown;
	ObscuredFloat rocketFuelRegenerationCooldownTime;
	ObscuredFloat rocketHeightIncreaseSpeed;
	ObscuredFloat rocketFuelRegenerationSpeed;
	ObscuredFloat rocketHeightIncreaseSpeedFactor;
	ObscuredFloat rocketHeightReductionSpeedFactor;
	ObscuredFloat minRocketJumpHeight;
	ObscuredFloat airResistance;
	ObscuredFloat mountFlyingHeightIncreaseSpeed;
	ObscuredFloat mountFlyingHeightIncreaseSpeedFactor;
	ObscuredFloat mountFlyingHeightReductionSpeedFactor;
	int jumpCounter;
	Il2CppArrayT<float>* jumpHeightReductionSpeed;
	Il2CppArrayT<float>* jumpHeightReductionSpeed60FPS;
	bool canUseRocket;
	bool canUseMountFlying;
	bool isTripleJumpSecondJumpDone;
	bool isTripleJumpFirstJumpDone;
	bool isDoubleJumpFirstJumpDone;
	Vector3 velocity;
	Vector3 deltaMovement;
	bool isJumpLanding;
	bool isStunnedBeforeTime;
	bool isStunnedBeforeGrounded;
	int resetStunnedBeforeTimeFixedUpdateCount;
	int resetStunnedBeforeTimeFixedUpdateCounter;
	int resetStunnedBeforeGroundedFixedUpdateCount;
	int resetStunnedBeforeGroundedFixedUpdateCounter;
	ObscuredFloat oxygenRegenerationSpeed;
	ObscuredFloat oxygenTakeHitFromWaterCooldownTime;
	ObscuredFloat oxygenConsumptionSpeed;
	ObscuredFloat oxygen;
	ObscuredFloat oxygenTakeHitFromWaterCooldown;
	ObscuredFloat takeHitFromInstaDamageWaterCooldown;
	ObscuredFloat takeHitFromInstaDamageWaterCooldownTime;
	float playerPoisonedCooldown;
	ObscuredFloat takeHitFromInstaDamageBlockCooldown;
	ObscuredFloat takeHitFromInstaDamageBlockCooldownTime;
	Vector3 bounceSphereDirectionHelper;
	float bounceSphereNormalizedDirectionX;
	float bounceSphereNormalizedDirectionY;
	float bounceSphereForce;
	bool isBounceSphereFromBlockDone;
	bool bounceSphereFromBlock;
	bool bounceSphereFromAIEnemy;
	bool isBounceSphereFromAIEnemyDone;
	float bounceHorizontalFactorWhenGrounded;
	float bounceVerticalFactorWhenHeaded;
	float bounceSphereAIEnemyForce;
	float bounceSphereAIEnemyNormalizedDirectionX;
	float bounceSphereAIEnemyNormalizedDirectionY;
	Vector3 bounceSphereAIEnemyDirectionHelper;
	float windYDirection;
	float windXDirection;
	float bananaFarmTimeCounter;
	bool isRocketDeactivatedByEmptyFuel;
	bool isRocketActive;
	bool isMountFlyingActive;
	bool isInvertedControls;
	int fishingState;
	DateTime invertedControlsEndTime;
	bool fishingLeftButton;
	bool fishingRightButton;
	bool leftButtonDown;
	bool leftButton;
	bool leftButtonUp;
	bool rightButton;
	bool rightButtonDown;
	bool rightButtonUp;
	bool jumpButtonDown;
	bool jumpButton;
	bool jumpButtonUp;
	bool useButtonDown;
	bool useButton;
	bool useButtonUp;
	bool leftButtonKeyDown;
	bool leftButtonKey;
	bool leftButtonKeyUp;
	bool rightButtonKeyDown;
	bool rightButtonKey;
	bool rightButtonKeyUp;
	bool isWarping;
	bool justWarped;
	bool isClickToUseFist;
	bool isJumpButtonReset;
	bool isDoneAtLeastOneFixedUpdateForResetKeys;
	bool isSkinColorByWeapon;
	bool shouldPlayBounceAudio;
	int skinColorIndexBeforeSkinColorByWeapon;
	DateTime skinColorByWeaponEndTime;
	Il2CppObject* playerBoxCollider2D;
	Vector2 playerBoxColliderSize;
	CharacterController2D* playerCharacterController2D;
	float cooldownCounterToForceQuitJumpWhenHeaded;
	float cooldownToForceQuitJumpWhenHeaded;
	unsigned char currentPlayerSortingLayerType;
	Vector3 currentPlayerPosition;
	Vector2i lastPlayerWaterMapPoint;
	Vector2i lastPlayerDoorMapPoint;
	Vector2i currentPlayerMapPoint;
	Vector2i currentServerPlayerMapPoint;
	Vector2i previousServerPlayerMapPoint;
	Vector2i tempCurrentPlayerMapPoint;
	int lastPlayerPositionDoorBlockType;
	int currentPlayerPositionBlockType;
	int lastPlayerPositionBlockWaterType;
	int currentPlayerPositionBlockWaterType;
	Vector2i currentPlayerAboveMapPoint;
	int currentPlayerPositionAboveBlockType;
	Vector2i currentPlayerAboveWaterMapPoint;
	int currentPlayerPositionAboveBlockWaterType;
	Vector2i currentPlayerRightMapPoint;
	int currentPlayerPositionRightBlockType;
	Vector2i currentPlayerBelowMapPoint;
	int currentPlayerPositionBelowBlockType;
	Vector2i currentPlayerLeftMapPoint;
	int currentPlayerPositionLeftBlockType;
	Vector2i previousLocalPlayerMapPoint;
	float currentPlayerPositionXCorrection;
	int elevatorBlockTypeHelper;
	Il2CppObject* pupilRight;
	Il2CppObject* pupilLeft;
	Vector2 pupilLeftOriginalPosition;
	Vector2 pupilRightOriginalPosition;
	Vector2 pupilLeftOffset;
	Vector2 pupilRightOffset;
	int pupilLeftDirection;
	int pupilRightDirection;
	Il2CppObject* pupilLeftSpriteRenderer;
	Il2CppObject* pupilRightSpriteRenderer;
	Il2CppObject* eyeLashes;
	Il2CppObject* eyeLids;
	Il2CppObject* eyeLidsSpriteRendererFemale;
	Il2CppObject* eyeLidsSpriteRendererMale;
	float doEyeLidsBlinkCooldownCounter;
	bool isBlinking;
	Il2CppObject* rotatingTopArm;
	Vector3 rotatingTopArmEulerAngles;
	bool useBattleHitMode;
	float cooldownTimeToActivateBlockInteraction;
	float cooldownCounterToActivateBlockInteraction;
	Il2CppObject* skinSpriteMaterial;
	Il2CppObject* normalSpriteMaterial;
	Il2CppObject* eyebrowsHueSatBrightSpriteRenderer;
	HueSaturationBrightnessTint currentEyebrowsHueSaturationBrightness;
	HueSaturationBrightnessTint lastEyebrowsHueSaturationBrightness;
	Il2CppArrayT<Il2CppObject*>* skinHueSatBrightSpriteRenderers;
	HueSaturationBrightnessTint currentSkinHueSaturationBrightness;
	HueSaturationBrightnessTint lastSkinHueSaturationBrightness;
	Il2CppObject* eyeballsHueSatBrightSpriteRenderer;
	HueSaturationBrightnessTint currentEyeballsHueSaturationBrightness;
	Il2CppObject* hairHueSatBrightSpriteRenderer;
	HueSaturationBrightnessTint currentHairHueSaturationBrightness;
	HueSaturationBrightnessTint lastHairHueSaturationBrightness;
	Il2CppObject* topEarRingHueSatBrightSpriteRenderer;
	HueSaturationBrightnessTint currentTopEarRingHueSaturationBrightness;
	HueSaturationBrightnessTint lastTopEarRingHueSaturationBrightness;
	Il2CppObject* topEarRingChildHueSatBrightSpriteRenderer;
	HueSaturationBrightnessTint currentTopEarRingChildHueSaturationBrightness;
	HueSaturationBrightnessTint lastTopEarRingChildHueSaturationBrightness;
	Il2CppObject* beardHueSatBrightSpriteRenderer;
	HueSaturationBrightnessTint currentBeardHueSaturationBrightness;
	HueSaturationBrightnessTint lastBeardHueSaturationBrightness;
	Il2CppObject* tailHueSatBrightSpriteRenderer;
	HueSaturationBrightnessTint currentTailHueSaturationBrightness;
	HueSaturationBrightnessTint lastTailHueSaturationBrightness;
	Il2CppObject* hatHueSatBrightSpriteRenderer;
	HueSaturationBrightnessTint currentHatHueSaturationBrightness;
	HueSaturationBrightnessTint lastHatHueSaturationBrightness;
	Il2CppObject* hatChildHueSatBrightSpriteRenderer;
	HueSaturationBrightnessTint currentHatChildHueSaturationBrightness;
	HueSaturationBrightnessTint lastHatChildHueSaturationBrightness;
	Il2CppObject* maskHueSatBrightSpriteRenderer;
	HueSaturationBrightnessTint currentMaskHueSaturationBrightness;
	HueSaturationBrightnessTint lastMaskHueSaturationBrightness;
	Il2CppObject* shirtHueSatBrightSpriteRenderer;
	HueSaturationBrightnessTint currentShirtHueSaturationBrightness;
	HueSaturationBrightnessTint lastShirtHueSaturationBrightness;
	Il2CppArrayT<Il2CppObject*>* otherHueSatBrightSpriteRenderers;
	HueSaturationBrightnessTint currentOtherHueSaturationBrightness;
	Il2CppObject* tempMaterialPropertyBlock;
	int maleEyeLidsIndexInSkinHueSatBrightSpriteRenderers;
	int faceIndexInSkinHueSatBrightSpriteRenderers;
	int femaleEyeLidsIndexInSkinHueSatBrightSpriteRenderers;
	bool isTakeHitNotStunned;
	float cooldownTimeToChangeColorTakeHitNotStunned;
	float cooldownCounterToChangeColorTakeHitNotStunned;
	int takeHitNotStunnedChangeColorCounter;
	HueSaturationBrightnessTint takeHitHueSaturationBrightnessLowValue;
	Il2CppObject* hitEffectPrefab;
	int hitEffectsAmount;
	Il2CppArrayT<Il2CppObject*>* hitEffectAnimations;
	int hitEffectAnimationsIndex;
	Il2CppObject* topArmItem;
	Il2CppObject* topArmGlove;
	Il2CppObject* throwBlockPrefab;
	int throwBlocksAmount;
	Il2CppArrayT<Il2CppObject*>* throwBlocks;
	int throwBlocksIndex;
	Vector3 throwBlockTargetPosition;
	int throwBlockBlockType;
	int throwBlockSelectedTool;
	bool isForceTopArmRotateDone;
	bool doBlocksNeedInputAfterReserved;
	Vector2i reservedMapPointWhenBlocksNeedInput;
	bool skipFirstFallPlayerDust;
	Il2CppObject* playerDust;
	Il2CppObject* playerWaterSplash;
	Il2CppObject* playerQuickSandSplash;
	Il2CppObject* playerBloodSplash;
	Il2CppObject* playerAcidSplash;
	Il2CppObject* playerWaterClearSplash;
	Il2CppObject* playerWaterDarkRiverSplash;
	Il2CppObject* playerOilSplash;
	Il2CppObject* playerNaphthaSplash;
	Il2CppObject* swimAudioSource;
	int lastPlayerDirection;
	int hitFromBlockBlockType;
	Vector2i hitFromBlockMapPoint;
	bool shouldCheckDoActionMultipleTouchesFlag;
	bool shouldCheckDoAction;
	bool shouldCheckDoActionMultiple;
	int bodyExpressionHelper_TODO_REMOVE;
	int faceHelper_TODO_REMOVE;
	Il2CppObject* playerRenderHelperGameObject;
	Il2CppObject* playerTextureRenderer;
	Il2CppObject* playerTextureMaterial;
	Vector2 playerTextureOffset;
	Vector2 playerTextureScale;
	Il2CppObject* playerNameTextMeshPro;
	Il2CppObject* playerNameSubMesh;
	Il2CppObject* activeSpeechBubble;
	Il2CppObject* activeTradeBubble;
	Il2CppObject* tradeBubbleTimerCoroutine;
	Il2CppObject* activeMultiplayerMinigameBubble;
	Il2CppObject* multiplayerMinigameBubbleTimerCoroutine;
	Vector3 healthBarMinScale;
	Vector3 healthBarOriginalScale;
	Vector3 healthBarMaxScale;
	Vector2 healthBarBackgroundOriginalSize;
	Vector2 healthBarBackgroundSize;
	Il2CppObject* healthBarParentGameObject;
	Vector3 healthBarParentOriginalLocalPosition;
	Il2CppObject* healthBarTransform;
	Il2CppObject* healthBarSpriteRenderer;
	Il2CppObject* healthBarBackgroundSpriteRenderer;
	Il2CppObject* healthBarShowFullIEnumerator;
	Il2CppObject* healthBarHideIEnumerator;
	Il2CppObject* oxygenBarParentGameObject;
	Vector3 oxygenBarParentOriginalLocalPosition;
	Il2CppObject* oxygenBarTransform;
	Il2CppObject* oxygenBarSpriteRenderer;
	Il2CppObject* oxygenBarBackgroundSpriteRenderer;
	Vector3 oxygenBarMaxScale;
	Vector3 oxygenBarOriginalScale;
	Vector3 oxygenBarMinScale;
	Vector2 oxygenBarBackgroundOriginalSize;
	Vector2 oxygenBarBackgroundSize;
	Il2CppObject* oxygenBarHideIEnumerator;
	bool touchIndicatorDone;
	int instakillLayerInt;
	int aiEnemyLayerInt;
	bool isFirstStartFallDone;
	Il2CppObject* rightDeathByColliderPointTransform;
	Il2CppObject* leftDeathByColliderPointTransform;
	Vector2i leftDeathByColliderMapPoint;
	Vector2i rightDeathByColliderMapPoint;
	float deathByColliderInColliderTimeWhenDeathHappens;
	float deathByColliderInColliderTimeCounter;
	Vector2 tempDeflectorDirection;
	int tempDeflectorBlockType;
	float tempDeflectorDistance;
	float tempDeflectorForce;
	Vector2 deflectorForceVector;
	Vector2i wiringResetPoint;
	Vector2i wiringStartPoint;
	Vector2i wiringWirePoint;
	Il2CppObject* wiringWireGameObject;
	Il2CppObject* wiringWireFollowToPoint;
	Il2CppObject* wiringWireTransform;
	Il2CppObject* wiringWireLineRenderer;
	bool wiringTouchIsDone;
	bool isPressurePadActive;
	Vector2i lastCheckedPressurePadMapPoint;
	Vector2i pressurePadMapPoint;
	Il2CppList<int>* nearEnoughProximitySensors;
	Vector2i lastCheckedProximitySensorMapPointActivate;
	Vector2i lastCheckedProximitySensorMapPointDeactivate;
	bool doMoveAnimationFlag;
	bool wrenchTouchIsDone;
	bool hasStartedRaceLocally;
	DateTime raceStartTime;
	Il2CppArrayT<Il2CppObject*>* spriteRenderersForPlayerCopy;
	Il2CppObject* directionTransformForPlayerCopy;
	Il2CppObject* hatChildSpriteRendererForPlayerCopy;
	Il2CppObject* topEarRingChildSpriteRendererForPlayerCopy;
	Il2CppObject* eyebrowsChildSpriteRendererForPlayerCopy;
	Il2CppObject* backParticleSystem;
	Il2CppObject* backDustParticleSystem;
	Il2CppObject* backAudioSource;
	Il2CppObject* neckParticleSystem;
	Il2CppObject* poisonedParticleSystem;
	Il2CppObject* potionEffectOnParticleSystem;
	Il2CppObject* badBowelsEffectParticleSystem;
	Il2CppObject* wrenchSpriteRenderer;
	Il2CppObject* wrenchGameObject;
	Il2CppObject* familiarPrefab;
	Il2CppObject* familiarFollowToPoint;
	Il2CppObject* familiarAnimator;
	int battleStateInLastMapPoint;
	Il2CppObject* playerInvertedControlsEffectAnimation;
	bool shouldDoLevelUpEffects;
	int shouldDoLevelUpEffectsNewLevel;
	float shouldDoLevelUpEffectsDelayCounter;
	float shouldDoLevelUpEffectsDelay;
	Il2CppObject* mountAudioUpdater;
	bool shouldDoSpecialDying;
	int specialDyingType;
	int specialDyingAnimation;
	Il2CppObject* specialDyingGameObject;
	Il2CppObject* specialDyingSpriteRenderer;
	Il2CppArrayT<Il2CppObject*>* specialDying;
	float specialDyingTimer;
	int specialDyingFrameIndex;
	Il2CppArrayT<Il2CppObject*>* facialExpressionButtons;
	bool isPortalAnimationActive;
	float portalAnimationLerp;
	float portalAnimationSpeed;
	Color portalAnimationColor;
	Vector2i portalAnimationTargetMapPointScaleOutInToCurrentWorld;
	float portalScaleAnimationSpeed;
	float portalScaleAnimationTimer;
	Vector3 portalAnimationPivot;
	Vector3 portalAnimationPivotFamiliar;
	Vector3 portalLocalScaleStart;
	Vector3 portalLocalScaleEnd;
	Vector3 portalEulerAnglesStart;
	Vector3 portalEulerAnglesEnd;
	Vector3 portalEulerAnglesEndIn;
	Vector3 portalEulerAnglesEndOut;
	PortalAnimationType portalAnimationType;
	bool isAwakeDone;
	bool isStartDone;
	bool jumpDebugFlag;
	float jumpDebugY;
	int jumpRedused;
	int lastAnimation;
	int lastDirection;
	HueSaturationBrightnessTint deathHelperHueSaturationBrightnessTint;
	bool takeHitHelperSetPlayerAllHueSatBrightToNormalFlag;
	ReviveKey tempReviveKey;
	Vector3 tempPlayerPosition;
	Vector2i playerEdgeMapPointHelper;
	Vector3 isPlayerInMapPointVector3Helper;
	bool setPlayerRenderOrderFlag;
	int playerRenderOrderLevel;
	Vector2i tempCurrentPlayerBelowMapPointForWithCollider;
	Vector2i lastMapPointInVortexPortal;
	Vector3 warpPositionFix;
	Il2CppObject* tempAIPetMonoBehaviourBase;
	int headAnimation;
	bool headForceAnimationCallDone;
	bool wasThereHeadForceAnimationInLastFrame;
	bool headOverrideKeepAnimationOn;
	float headForceKeepOnTime;
	Il2CppObject* playerHeadAnimator;
	Il2CppObject* playerTorsoAnimator;
	Il2CppObject* playerTopArmAnimator;
	Il2CppObject* playerBottomArmAnimator;
	Il2CppObject* playerLegsAnimator;
	Il2CppObject* playerBackAnimator;
	int tempAnimationTorso;
	int tempAnimationTopArm;
	int tempAnimationBottomArm;
	int tempAnimationLegs;
	int tempAnimationBack;
	int tempAnimation;
	Vector3 tempDoTakeHitNotStunnedAnimationVectorHelper;
	Il2CppObject* tempDoTakeHitNotStunnedAnimationStrikerGameObject;
	bool didTakeVelocityChangeFromHit;
	int velocityChangeFromHitDirection;
	float velocityChangeFromHit;
	float velocityChangeFromHitMax;
	float playerHitOtherPlayerVelocityChangeSpeed;
	Color tempColorForSetPlayerAlpha;
	HueSaturationBrightnessTint tempHueSaturationBrightnessTintForPlayerEyebrows;
	HueSaturationBrightnessTint tempHueSaturationBrightnessTintForPlayerSkin;
	Vector3 directionWrapperLocalPosition;
	Il2CppObject* playerOverheadNotificationGameObject;
	Il2CppObject* playerOverheadNotificationPrefab;
	Il2CppObject* fishingLine;
	Il2CppObject* fishStrikesGameObject;
	Il2CppObject* fishStrikesPrefab;
	InventoryKey lureIKBeforeFishing;
	float cooldownToUseFistMultiplier;
	bool isSubAquaticPerkActive;
	float perksFloatHelper;
	Il2CppObject* worldLightingPlayerLightGameObject;
	Il2CppObject* worldLightingPlayerLightTransform;
	Il2CppObject* worldLightingPlayerLightSpriteRenderer;
	Vector2i checkJetRaceAwardGateMapPoint;
	bool checkJetRaceAwardGateShouldCollect;
	float checkJetRaceAwardGateDistanceX;
	float checkJetRaceAwardGateDistanceY;
};
struct StaticPlayer_Static
{
	Il2CppString* playerName;
	bool IsNetworkConnectionOK;
	Il2CppString* email;
	Il2CppString* theRealPlayername;
	Il2CppString* currentWotwName;
	bool emailVerified;
	Il2CppString* reportToKeep;
	bool worldJoinRetryAttemptIsOk;
	bool changedServerOnPortalEntry;
	Il2CppString* lastWorldBeforeTeleport;
	Il2CppString* lastWorldBeforeDisconnect;
	Il2CppArrayT<DateTime>* currentWorldRandomEventEndTimes;
	Il2CppArrayT<int>* currentWorldRandomEvents;
	NetherWorldEntryPoint netherWorldEntryPoint;
	Il2CppObject* dataChanged;
	PlayerData* _playerData;
};
struct NetworkClient_Static
{
	Il2CppString* currentWorld;
	Il2CppString* currentWorldEntryPointID;
	int maxSecondsInLimbo;
	float pingInterval;
	int reconnectAttempts;
	Il2CppString* joinWorldOnConnect1;
	Il2CppString* joinWorldOnConnect2;
	bool restartGameIfNetworkClientIsRemoved;
	int serverConnectAttempts;
	bool specialFlag;
};
struct NetworkPlayer
{
	Il2CppClass* klass;
	MonitorData* monitor;
	Il2CppObject* gameObject;
	Player* playerScript;
	Il2CppObject* simpleRemoteInterpolationScript;
	Il2CppString* clientId;
	Il2CppString* name;
};
struct DailyQuest
{
	Il2CppClass* klass;
	MonitorData* monitor;
	Il2CppString* _ID;
	Il2CppString* name;
	int currentStep;
	int rarity;
	Il2CppObject* targetPlayerData;
	bool isCompleted;
	void*/*Action`1*/ OnQuestCompleted;
	void*/*Action`1*/ OnStepCompleted;
	bool isTutorialQuest;
	Il2CppList<Il2CppObject*>* steps;
	Il2CppString* iconString;
	bool isClanQuest;
};
struct InventoryControl
{
	Il2CppClass* klass;
	MonitorData* monitor;
	Il2CppObject* beltControl;
	Il2CppObject* inventoryTransform;
	Il2CppObject* inventoryBG;
	Il2CppObject* inventoryScroll;
	Il2CppObject* cloneableInventorySlotParent;
	Il2CppObject* inventoryGridLayoutGroup;
	Il2CppObject* tradeOverlay;
	Il2CppObject* ownTradeItems;
	Il2CppObject* partnerTradeItems;
	Il2CppObject* ownTradeItemsRectTransform;
	Il2CppObject* partnerTradeItemsRectTransform;
	Il2CppObject* tradeAcceptButton;
	Il2CppObject* tradeCancelButton;
	Vector2 halfHeightInventorySize;
	Vector2 halfHeightInventoryBgSize;
	Vector2 fullHeightInventoryBgSize;
	int slotsPerRow;
	int slotSizeInPixels;
	float magicInventoryViewportOffset;
	float maxInventoryY;
	float beltShownY;
	float buttonShownY;
	bool forceButtonAlphaState;
	Il2CppArrayT<Vector3>* fadePointPositions;
	bool firstTopButtonsShown;
	bool secondTopButtonsShown;
	bool thirdTopButtonsShown;
	bool fourthTopButtonsShown;
	bool fifthTopButtonsShown;
	bool actionButtonsShown;
	bool k__BackingField;
	Il2CppObject* chatRef;
	void*/*ITween`1*/ beltButtonTween;
	void*/*ITween`1*/ beltTween;
	int halfInventoryHeightInPixels;
	int ourBlockSizeMultiplier;
	int playerSlotAmount;
	Il2CppObject* currentInventorySelectionHighlight;
	int currentInventorySelectionNumber;
	int currentTapAndHoldSelectionNumber;
	Il2CppDictionary* lastPotionUseResultWaitTimestamps;
	Il2CppArrayT<InventoryKey>* currentInventoryItems;
	Il2CppArrayT<short>* currentItemCounts;
	Il2CppList<Il2CppObject*>* currentInventorySlots;
	Il2CppDictionary* unseenItemsAndSeenTimeStamps;
	int bTimeInSeconds;
	int slotNumberForTutorialShirt;
	Il2CppObject* inventoryPointerGesture;
	Il2CppObject* actionPopupCoroutine;
	Il2CppArrayT<Il2CppObject*>* actionPopupActions;
	Il2CppArrayT<Il2CppString*>* actionPopupTexts;
	Il2CppArrayT<Il2CppString*>* actionPopupTextCombine;
	Il2CppArrayT<Il2CppString*>* actionPopupTextConvert;
	Il2CppArrayT<Il2CppString*>* actionPopupTextFuse;
	Il2CppArrayT<Il2CppString*>* actionPopupTextFamInfo;
	Il2CppArrayT<Il2CppString*>* actionPopupTextBanInfo;
	Il2CppArrayT<Il2CppString*>* actionPopupTextMessageInfo;
	Il2CppArrayT<Il2CppString*>* actionPopupTextRepairMiningPickaxe;
	Il2CppString* slotName;
	Il2CppString* slotButtonName;
	Il2CppString* slotSelectedName;
	Il2CppString* slotAmountTextName;
	Il2CppString* slotUsageSymbolName;
	Il2CppString* slotSpriteName;
	Il2CppString* slotSpriteShadowName;
	Il2CppString* slotRarityBadgeName;
	bool storageUIOpen;
	bool storageWaitingForItem;
	void*/*Action`1*/ storageActionAfterSelection;
	bool tradeOverlayOpen;
	Il2CppObject* slotWaitingForItem;
	Il2CppObject* glowingSlot;
	bool glowAnimationPlaying;
	int slotWaitingForItemIndex;
};
struct FramesArray
{
	int frameCount;
	int realFrameNumber;
};
struct AnimationsArray
{
	Il2CppString* helper;
	int animation;
	int nextAnimation;
	bool loop;
	int maxLoopCount;
	bool playToEnd;
	int frameRate;
	float timeToStayInOneFrame;
	Il2CppArrayT<FramesArray>* framesArray;
	Il2CppArrayT<int>* realFramesArray;
};
enum class SoundType
{
	CollectItem,
	CollectGem,
	ChangeWearable,
	BreakBlock,
	PlayerHit,
	PlayerShoot,
	BlockTakeHit,
	CreateBlock,
	ActivateBlock,
	DeactivateBlock,
	EnterWater,
	ExitWater,
	ButtonClick,
	TrapDoAction,
	GotHitFromBlock,
	PlayerDying,
	GoInPortal,
	GoOutPortal,
	PlayerBounce,
	PlayerBounceWithJump,
	PlayerJump,
	PlayerLanding,
	PlayerStep,
	GoInTo,
	GoOutFrom,
	LotteryChange,
	LotteryResult,
	LevelUpPlayer,
	ChangeBackground,
	PlayerWings,
	OpenWrenchMenu,
	CloseWrenchMenu,
	MoveItemToContainer,
	TakeItemFromContainer,
	OtherPlayerDying,
	PlantSeed,
	CrossbreedSeed,
	GotHitFromOtherPlayer,
	TradeAccept,
	TradePopup,
	TradeSuccess,
	TradeAddItemToSlot,
	TradeTakeItemFromSlot,
	OtherPlayerEnterWorld,
	OtherPlayerExitWorld,
	FriendRequestSent,
	TradeWarning,
	SelectionClick,
	PurchaseSuccess,
	PurchaseFail,
	ClaimNormalPrize,
	ClaimMainPrize,
	BonusRaffle,
	ShopFlipCard,
	ShopFlipCardRare,
	ShopFlipCardUltraRare,
	PrizeAcquired,
	ClaimPrizeShow,
	ThrowBlock,
	AchievementNotify,
	StarHit,
	PotsOfGemsEventStart,
	PotsOfGemsEventFail,
	PotsOfGemsEventSuccess,
	PrivateMessageNotification,
	LockCompress,
	PlayerRocketEmpty,
	ShopFlipCardLegendary,
	BlockTakeHitExtraAudio,
	DeathByBlock,
	CollectItemFromGiftBox,
	DailyQuestCompletedNotification,
	Fertilized,
	SummonAppear,
	SummonDisappear,
	SummerEventStart,
	SummerEventFail,
	SummerEventSuccess,
	PlayerStepExtra,
	PlayerJumpExtra,
	PlayerLandingExtra,
	ChangeFamiliar,
	PuzzleDrag,
	PuzzleSolved,
	PuzzleFail,
	BattleOn,
	BattleOff,
	BattleKill,
	BattleCrit,
	SpiritAppear,
	SpiritDisappear,
	SpiritDying,
	ChangePlayerCostume,
	PlayerCostumeWerewolfBodyExpression,
	ResetPlayerCostume,
	HalloweenTowerStart,
	HalloweenTowerEnd,
	CostumeDying,
	HalloweenTowerCounter,
	HalloweenTowerDying,
	GotHitFromAIEnemy,
	AIEnemyGemBurst,
	AIEnemyPreCharge,
	AIEnemyStep,
	AIEnemyShoot,
	AIEnemyDying,
	AIEnemyChargeStep,
	NetherStart,
	NetherExitOpen,
	CollectItemWithSpecialAudio,
	NetherEndSuccess,
	NetherEndFail,
	NetherWorldNotification,
	FireworksLaunch,
	FireworksExplosion,
	FireworksCrackle,
	XmasSnowflakeDying,
	UseSrollEffect,
	DeepNetherExitOpen,
	DeepNetherStart,
	DeepNetherEndSuccess,
	DeepNetherEndFail,
	DeepNetherNotification,
	AIEnemyEnemyDieBurst,
	ValentinesDayHeartDying,
	ButterflyDisappear,
	EasterEggAppear,
	EasterEggDisappear,
	BlueParticleAppear,
	BlueParticleDisappear,
	BlueParticleDying,
	ActivateNetherGroupPortal,
	DeactivateNetherGroupPortal,
	UseRecycler,
	ActivateLabExitPortal,
	ActivateBluePortal,
	DeactivateBluePortal,
	AIEnemySelfDestruction,
	LabBossRoomDoorOpen,
	LabBossJetStart,
	AIEnemyActivateAnimation,
	AIEnemyPreStomp,
	AIEnemyStomp,
	BossDyingSmallExplosion,
	BossDyingLargeExplosion,
	LabStart,
	DefeatTheBoss,
	LabEndSuccess,
	LabEndFail,
	LabTopNotification,
	LabBossCrash,
	NoobLockUpgrade,
	WishingWellThrowCoin,
	WishingWellPrize1,
	WishingWellPrize2,
	WishingWellPrize3,
	WishingWellPrize4,
	SwordInStoneSuccess,
	UsePotion,
	PotionEffectEnd,
	WishingWellPrize5,
	WishingWellPrize6,
	WishingWellPrize7,
	ExtraDropFromAIEnemy,
	Recall,
	FishingStart,
	FishStrikes,
	FishLost,
	FishingBaitStolen,
	FishRun,
	FishLandButtonActivated,
	FishCaught,
	FishPopupWin,
	FishPopupLose,
	FishSuccess,
	FishHook,
	FishRunRemote,
	FishLostRemote,
	FishSuccessPersonalRecord,
	FishSuccessWorldRecord,
	FishSuccessTopTenRecord,
	FishingTournamentTicketEnd,
	PlayerDyingExplosion,
	BadBowels,
	PlayerDyingDieCloud,
	OtherPlayerDyingDieCloud,
	Typewriter,
	CinematicsEnd,
	TutorialPodEffect,
	RiftDisappear,
	WiringUseTool,
	WiringConnect,
	WiringDisconnect,
	WiringCancel,
	WorldScreenshot,
	ChangeWeather,
	LevelUpClan,
	NetherBossWraithShieldAppear,
	NetherBossWraithShieldDisappear,
	PetTalk1,
	PetTalk2,
	PetEat1,
	PetAngry1,
	PetClean,
	PetFreeze,
	PetAdventureStartEnd,
	PetInteractSuccess,
	ChangeLighting,
	ActivatePortalCryptic,
	DeactivatePortalCryptic,
	BlockTakeHitWeaponBroken,
	WeaponPickaxeBroken,
	AIEnemySpawn,
	AIEnemyDisappear,
	MiningStart,
	PickaxeRepair,
	PickaxeUpgrade,
	InsertCoin,
	RouletteSpin,
	RoulettePrizeOneStar,
	RoulettePrizeTwoStar,
	RoulettePrizeThreeStar,
	RoulettePrizeFourStar,
	RoulettePrizeFiveStar,
	MountFlyingEngine,
	ActivateJetRaceGroupPortal,
	DeactivateJetRaceGroupPortal,
	PlayerDyingFlyingMountExplosion,
	PlayerActivatedJetRaceAwardGate,
	JetRaceSawStop,
	InsertCoin2,
	JetRaceStart,
	JetRaceEnd,
	JetRaceCounter,
	JetRaceDying,
	BestSetCardAppear,
	BestSetCardSelect,
	BestSetWin,
	BestSetBadge,
	CardCollectionMoveToDeck,
	CardCollectionRemoveFromDeck,
	CardCollectionDust,
	CardCollectionCraft,
	CardCollectionToInventory,
	CardConsumeCardFromInventory,
	CardPackOpen,
	CardPackCardReveal,
	CardPackCardRevealGold,
	CardGameOpenBoard,
	CardGameStartDeck,
	CardGameDealFromDeck,
	CardGameStartPlayerTurn,
	CardGameEndPlayerTurn,
	CardGameSelectCard,
	CardGameCardToBoard,
	CardGameDuel,
	CardGameYouWin,
	CardGameOpponentWin,
	CardGameNumericTimerChange,
	CardGameNumericTimerZero,
	CardGameOpenUI,
	CardGameMoveCard,
	CardCollectionAddToDeck,
	CardGameEffectOrActionImpact,
	CardGameDiscardFromDeck,
	NONE,
};
enum class AIEnemyLookDirectionType
{
	None,
	MoveFlipHorizontal,
	MoveFlipVertical,
	LookAtPlayerHorizontal,
	LookAtPlayerVertical,
	LookAtPlayerBoth,
	MoveFlipBoth,
	RotationFlipHorizontal,
	RotationFlipVertical,
};
enum class AIEnemySyncCorrectionType
{
	None,
	TotalMoveDistanceSpeedCorrection,
	VelocityAndPositionSpeedCorrection,
	TooFarDistancePosition,
};
enum class AIEnemyAnimationAnimationNames
{
	None,
	Idle,
	Walk,
	Fly,
	Hit,
	TakeHit,
	Dying,
	PreCharge,
	Charge,
	LateCharge,
	Shoot,
	PreSpell,
	CastSpell,
	SelfDestruction,
	PreShoot,
	ShootDown,
	ShootUp,
	ShootFront,
	FromIdleToPreCharge,
	FromStunToPreCharge,
	FromStunToIdle,
	Stun,
	ShootBottom,
	ShootTop,
	FromStunToFlight,
	FromFlightToPreCharge,
	FromFlightToShoot,
	FlightShoot,
	FromFlightShootToFlight,
	FromFlyToFlyShooter,
	FlyShooter,
	FromFlyShooterToFly,
	Stomp,
	FromStompStunToFlight,
	StompStun,
	HoldSpell,
	PostSpell,
	Spawn,
	Disappear,
	END_OF_THE_ENUM,
};
struct AIEnemyAnimator
{
	Il2CppClass* klass;
	MonitorData* monitor;
	Il2CppObject* myTransform;
	Il2CppObject* aiEnemyMonoBehaviourBase;
	bool isStarted;
	bool isPlaying;
	bool shouldPlayToEnd;
	bool shouldStopPlayingIfNewAnimationIsNotIdle;
	float animationTime;
	float timeToStayInOneFrame;
	int currentFrameNumber;
	int currentEyeLidsFrameNumber;
	int loopCounter;
	float keepThisAnimationOnCooldownCounter;
	bool showGizmos;
	Il2CppArrayT<Il2CppObject*>* subAIEnemyAnimators;
	bool isSubAnimator;
	Il2CppObject* bodyTransform;
	int bodyTransformOriginalOrderInLayer;
	Il2CppObject* bodySpriteRenderer;
	Il2CppObject* eyeLidsTransform;
	Il2CppObject* eyeLids;
	int eyeLidsTransformOriginalOrderInLayer;
	Il2CppObject* eyeLidsSpriteRenderer;
	int aiEnemyType;
	int sortingOrderLevel;
	Vector2 pivotHelper;
	Vector3 localPositionHelper;
	int currentAnimation;
	Il2CppObject* directionTransform;
	float doEyeLidsBlinkCooldownCounter;
	bool isBlinking;
	int lastRealFrameNumberForPlayAudio;
	int tempSoundType;
	Il2CppArrayT<AnimationsArray>* animationsArray;
	Color tempColorForSetAlpha;
};
struct ProjectileData
{
	Il2CppClass* klass;
	MonitorData* monitor;
	Il2CppObject* shooter;
	float initialWaitTime;
	bool waiting;
};
enum class AIEnemyDirection
{
	None,
	Up,
	Right,
	Down,
	Left,
	END_OF_THE_ENUM,
};
enum class AIDamageModelType
{
	None,
	TouchStun,
	TouchKnockbackWeak,
	TouchKnockbackMedium,
	TouchKnockbackStrong,
	TouchInstaKill,
	AfterDeath,
	END_OF_ENUM,
};
struct AIDamageModel
{
	Il2CppClass* klass;
	MonitorData* monitor;
	int type;
	Il2CppObject* parentObject;
	float damageMultiplier;
};
enum class AIHurtModelType
{
	None,
	Default,
	Immortal,
	END_OF_ENUM,
};
struct AIHurtModel
{
	Il2CppClass* klass;
	MonitorData* monitor;
	int type;
	Il2CppObject* parentObject;
};
enum class AIBehaviorType
{
	None,
	PingPong,
	Walk,
	StandAndGuard,
	Charge,
	ChargeThrough,
	AimingSpellCaster,
	HorizontalShooter,
	ProjectileColliding,
	ProjectileNonColliding,
	ProjectileNonCollidingCurve,
	Patrol,
	MultiSpellCaster,
	GuardHomingNonColliding,
	AimingMultiSpellCaster,
	PingPongShooter,
	DyingStationary,
	HorizontalMultiShooter,
	Idle,
	TravelAir,
	TravelGround,
	ProjectileNonCollidingGravity,
	ProjectileCollidingGravity,
	AngleMultiShooter,
	Stomp,
	HorizontalShooterGuard,
	ProjectileHoming,
	NetherBossWraithLemniscateBehavior,
	HideAndSpawn,
	Summoner,
	FireOnce,
	Ambush,
	TravelToPlayer,
	END_OF_ENUM,
};
struct AIBehavior
{
	Il2CppClass* klass;
	MonitorData* monitor;
	int type;
	Il2CppObject* parentObject;
	Il2CppArrayT<float>* storedParameters;
	long long currentBehaviorStartTimeInTicks;
};
enum class AIEnemyType
{
	None,
	TestBlob,
	FlameBallGround,
	FlameBallAir,
	FlameBallCharging,
	ArmoredWalkerCharge,
	RobeCaster,
	TentacleShooter,
	RobeCasterSpell,
	TentacleShooterBullet,
	StaffCaster,
	StaffCasterSpell,
	Wraith,
	WheeledBuzzSaw,
	DrillCharger,
	SelfDestructCannon,
	SelfDestructCannonBullet,
	PropellerBomber,
	PropellerBomberBomb,
	ShotgunPatrol,
	ShotgunPatrolBullet,
	LaboratoryBoss,
	LaboratoryBossProjectileA,
	LaboratoryBossProjectileB,
	LaboratoryBossProjectileC,
	LaboratoryBossProjectileD,
	PropellerBomberPropeller_Visual,
	LaboratoryBossTreadFront_Visual,
	LaboratoryBossTreadBack_Visual,
	LaboratoryBossCannonConnector_Visual,
	LaboratoryBossCannonBottom_Visual,
	LaboratoryBossCannonTop_Visual,
	LaboratoryBossSkull_Visual,
	LaboratoryBossBodyTop_Visual,
	LaboratoryBossBodyGlass_Visual,
	LaboratoryBossVillain_Visual,
	LaboratoryBossBodyTop_VisualOffset,
	LaboratoryBossCannonBottom_VisualOffset,
	LaboratoryBossCannonTop_VisualOffset,
	LaboratoryBossPropulsion_Visual,
	LaboratoryBossSkull_VisualOffset,
	LaboratoryBossJetFlame,
	LaboratoryBossDustLeft_Visual,
	LaboratoryBossDustRight_Visual,
	LaboratoryBossProjectileE,
	SummerFish,
	NetherBossWraith,
	NetherBossWraithSpell,
	NetherBossWraithShield,
	Bat,
	DeepMaggot,
	Gassy,
	RockyHorror,
	DeepMaggotBullet,
	RockyHorrorRocks,
	END_OF_ENUM,
};
struct AIBase
{
	Il2CppClass* klass;
	MonitorData* monitor;
	int enemyType;
	int id;
	int parentID;
	int width;
	int height;
	Il2CppArrayT<Il2CppObject*>* behaviors;
	int currentBehavior;
	Il2CppArrayT<Il2CppObject*>* hurtModels;
	int currentHurtModel;
	Il2CppArrayT<Il2CppObject*>* damageModels;
	int currentDamageModel;
	float mapPointX;
	float mapPointY;
	float xVelocityInBlocksPerSecond;
	float yVelocityInBlocksPerSecond;
	float totalMoveDistance;
	int direction;
	bool isAlive;
	int health;
	Il2CppObject* projectileData;
	Il2CppString* targetPlayerID;
	bool markedForRemoval;
};
struct AIEnemyMonoBehaviourBase
{
	Il2CppClass* klass;
	MonitorData* monitor;
	Il2CppObject* somePaddingIDFK;
	Il2CppObject* myTransform;
	Il2CppObject* myGameObject;
	Il2CppObject* myCollider;
	Il2CppObject* directionWrapperTransform;
	Vector3 tempDirectionScale;
	Vector3 tempDirectionEulerAngles;
	Vector3 direction;
	float speedCorrection;
	float speedCorrectionStartValue;
	float speedCorrectionMiddleValue;
	float speedCorrectionEndValue;
	float speedCorrectionBackToNormalSpeed;
	float speedCorrectionBackToNormalSpeedMinValue;
	float speedCorrectionBackToNormalSpeedMaxValue;
	float speedCorrectionBackToNormalLerpValue;
	float originalSpeedCorrection;
	float maxSpeedCorrectionAdd;
	float distanceWhenSpeedCorrectIsMax;
	Vector3 wantedPosition;
	Vector3 serverAccuratePosition;
	Vector3 wantedAccuratePosition;
	bool setTempBackTo;
	bool tempIsBehind;
	float tempTotalMoveDistance;
	Vector3 tempPosition;
	float tempVelocityX;
	float tempVelocityY;
	float tempDistance;
	float maxDistanceTooFar;
	int tooFarAwayCounter;
	int maxTooFarAwayCount;
	AIBase* aiBase;
	AIEnemyAnimator* aiEnemyAnimator;
	int currentAnimation;
	int defaultAnimation;
	int aiEnemySyncCorrectionType;
	int lookDirectionType;
	int originalLookDirectionType;
	Il2CppObject* lookDirectionFunction;
	int damageType;
	Il2CppObject* damageFunction;
	float doDamageCooldownTime;
	float doDamageCooldownCounter;
	Il2CppArrayT<Il2CppObject*>* spriteGameObjects;
	bool shouldUseHueSatBrightTakeHit;
	Il2CppArrayT<Il2CppObject*>* spriteRenderers;
	Color currentColor;
	Color normalColor;
	Color takeHitHighColor;
	float takeHitMaxColor;
	bool isTakeHitOn;
	float cooldownTimeToChangeColorTakeHitNotStunned;
	float cooldownCounterToChangeColorTakeHitNotStunned;
	int takeHitNotStunnedChangeColorCounter;
	bool isActive;
	bool isWaitingForAnimation;
	bool isWaitingForVisual;
	Vector3 deactivatePosition;
	bool isStarted;
	Il2CppArrayT<Vector2i>* currentRealMapPoints;
};
enum class StatusIconType
{
	None,
	InMenus,
	Typing,
	Trading,
	CardGame,
};
struct LockWorldData
{
	Il2CppClass* klass;
	MonitorData* monitor;
	Il2CppObject* somePaddingIDFK;
	Il2CppObject* somePadding2IDFK;
	Il2CppString* playerWhoOwnsLockId;
	Il2CppString* playerWhoOwnsLockName;
	Il2CppList<Il2CppString*>* playersWhoHaveAccessToLock;
	Il2CppList<Il2CppString*>* playersWhoHaveMinorAccessToLock;
	bool isOpen;
	bool punchingAllowed;
	DateTime creationTime;
	DateTime lastActivatedTime;
	bool isBattleOn;
};
struct UploadHandler
{
	Il2CppClass* klass;
	MonitorData* monitor;
	void*/*IntPtr*/ m_Ptr;
};
struct UnityWebRequest
{
	Il2CppClass* klass;
	MonitorData* monitor;
	void*/*IntPtr*/ m_Ptr;
	Il2CppObject* m_DownloadHandler;
	Il2CppObject* m_UploadHandler;
	Il2CppObject* m_CertificateHandler;
	Il2CppObject* m_Uri;
};