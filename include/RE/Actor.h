#pragma once

#include "skse64/GameEvents.h"  // BSTEventSink
#include "skse64/GameReferences.h"  // IPostAnimationChannelUpdateFunctor, SpellArray, Actor

#include "Offsets.h"

#include "RE/ActorProcessManager.h"  // ActorProcessManager
#include "RE/ActorState.h"  // ActorState
#include "RE/ActorValueOwner.h"  // ActorValueOwner
#include "RE/BGSEntryPointPerkEntry.h"  // BGSEntryPointPerkEntry
#include "RE/bhkCharacterMoveFinishEvent.h"  // bhkCharacterMoveFinishEvent
#include "RE/BSTransformDeltaEvent.h"  // BSTransformDeltaEvent
#include "RE/MagicTarget.h"  // MagicTarget
#include "RE/TESNPC.h"  // TESNPC
#include "RE/TESObjectREFR.h"  // TESObjectREFR

class BaseExtraList;
class BGSPerk;
class SpellItem;
class TESFaction;
class TESForm;
class TESRace;


namespace RE
{
	class BaseExtraList;
	class PerkEntryVisitor;


	class Actor :
		public TESObjectREFR,
		public MagicTarget,
		public ActorValueOwner,
		public ActorState,
		public BSTEventSink<BSTransformDeltaEvent>,
		public BSTEventSink<bhkCharacterMoveFinishEvent>,
		public IPostAnimationChannelUpdateFunctor
	{
	private:
		enum Flags1 : UInt32
		{
			kFlags1_AIEnabled		= 1 << 1,
			kFlags1_PlayerTeammate	= 1 << 26,
			kFlags1_Guard			= 1 << 30
		};


		enum Flags2 : UInt32
		{
			kFlags2_HasInteraction		= 1 << 1,
			kFlags2_CanDoFavor			= 1 << 7,
			kFlags2_Trespassing			= 1 << 12,
			kFlags2_KillMove			= 1 << 14,
			kFlags2_AttackedByAllActors	= 1 << 15,
			kFlags2_CommandedActor		= 1 << 16,
			kFlags2_Essential			= 1 << 18,
		};

	public:
		enum { kTypeID = kFormType_Character };


		enum SlotType : UInt32
		{
			kSlotType_LeftHand = 0,
			kSlotType_RightHand,
			kSlotType_Unknown,
			kSlotType_PowerOrShout,

			kNumSlots
		};


		struct Data228
		{
			UInt32	unk0;
			UInt32	unk4;
			UInt32	unk8;
		};


		virtual	~Actor();

		virtual void	Unk_9C(void);
		virtual void	Unk_9D(void);
		virtual void	Unk_9E(void);
		virtual void	Unk_9F(void);
		virtual void	Unk_A0(void);
		virtual void	Unk_A1(void);
		virtual void	Unk_A2(void);
		virtual void	PlaySounds(TESForm* a_item, bool a_isPickup, bool a_unk);
		virtual void	Unk_A4(void);
		virtual void	Unk_A5(void);
		virtual void	DrawSheatheWeapon(bool a_draw);
		virtual void	Unk_A7(void);
		virtual void	Unk_A8(void);
		virtual void	Unk_A9(void);
		virtual void	Unk_AA(void);
		virtual void	Unk_AB(void);
		virtual void	Unk_AC(void);
		virtual void	Unk_AD(void);
		virtual void	Unk_AE(void);
		virtual void	Unk_AF(void);
		virtual void	Unk_B0(void);
		virtual void	Unk_B1(void);
		virtual void	Unk_B2(void);
		virtual void	Unk_B3(void);
		virtual void	Unk_B4(void);
		virtual void	Unk_B5(void);
		virtual void	Unk_B6(void);
		virtual void	Unk_B7(void);
		virtual void	Unk_B8(void);
		virtual void	Unk_B9(void);
		virtual void	Unk_BA(void);
		virtual void	Unk_BB(void);
		virtual void	Unk_BC(void);
		virtual void	Unk_BD(void);
		virtual void	Unk_BE(void);
		virtual void	Unk_BF(void);
		virtual void	Unk_C0(void);
		virtual void	Unk_C1(void);
		virtual void	Unk_C2(void);
		virtual void	Unk_C3(void);
		virtual void	Unk_C4(void);
		virtual void	Unk_C5(void);
		virtual void	Unk_C6(void);
		virtual void	Unk_C7(void);
		virtual void	Unk_C8(void);
		virtual void	Unk_C9(void);
		virtual void	Unk_CA(void);
		virtual void	Unk_CB(void);
		virtual void	PickUpItem(TESObjectREFR* a_item, UInt32 a_count, bool a_arg3, bool a_playSound);
		virtual void	Unk_CD(void);
		virtual void	Unk_CE(void);
		virtual void	Unk_CF(void);
		virtual void	Unk_D0(void);
		virtual void	Unk_D1(void);
		virtual void	Unk_D2(void);
		virtual void	Unk_D3(void);
		virtual void	Unk_D4(void);
		virtual void	Unk_D5(void);
		virtual void	Unk_D6(void);
		virtual void	Unk_D7(void);
		virtual void	Unk_D8(void);
		virtual void	Unk_D9(void);
		virtual void	Unk_DA(void);
		virtual void	Unk_DB(void);
		virtual void	Unk_DC(void);
		virtual void	Unk_DD(void);
		virtual void	Unk_DE(void);
		virtual void	Unk_DF(void);
		virtual void	Unk_E0(void);
		virtual void	Unk_E1(void);
		virtual void	Unk_E2(void);
		virtual bool	IsInCombat();
		virtual void	Unk_E4(void);
		virtual void	Unk_E5(void);
		virtual void	Unk_E6(void);
		virtual void	Unk_E7(void);
		virtual void	Unk_E8(void);
		virtual void	Unk_E9(void);
		virtual void	Unk_EA(void);
		virtual void	Unk_EB(void);
		virtual void	Unk_EC(void);
		virtual void	Unk_ED(void);
		virtual void	Unk_EE(void);
		virtual void	Unk_EF(void);
		virtual void	Unk_F0(void);
		virtual void	Unk_F1(void);
		virtual void	Unk_F2(void);
		virtual void	Unk_F3(void);
		virtual void	Unk_F4(void);
		virtual void	Unk_F5(void);
		virtual void	Unk_F6(void);
		virtual void	AdvanceSkill(UInt32 a_skillId, float a_points, UInt32 a_unk1, UInt32 a_unk2);
		virtual void	Unk_F8(void);
		virtual bool	IsInFaction(TESFaction* faction);
		virtual void	VisitPerks(void);
		virtual void	AddPerk(BGSPerk* a_perk, UInt32 a_unk1);
		virtual void	RemovePerk(BGSPerk* a_perk);
		virtual void	Unk_FC(void);
		virtual void	Unk_FD(void);
		virtual bool	CanProcessEntryPointPerkEntry(BGSEntryPointPerkEntry::EntryPointType a_entryType);
		virtual void	VisitEntryPointPerkEntries(BGSEntryPointPerkEntry::EntryPointType a_entryType, PerkEntryVisitor& a_visitor);


		bool			VisitFactions(::Actor::FactionVisitor& a_visitor);
		TESForm*		GetEquippedObject(bool a_abLeftHand);
		void			UpdateSkinColor();
		void			UpdateHairColor();
		void			QueueNiNodeUpdate(bool a_updateWeight);
		bool			HasPerk(BGSPerk* a_perk);
		UInt16			GetLevel();
		void			SetRace(TESRace* a_race, bool a_isPlayer);
		void			UpdateWeaponAbility(TESForm* a_weapon, BaseExtraList* a_extraData, bool a_bLeftHand);
		void			UpdateArmorAbility(TESForm* a_armor, BaseExtraList* a_extraData);
		bool			IsHostileToActor(::Actor* a_actor);
		void			ResetAI(UInt32 a_unk1, UInt32 a_unk2);

		TESNPC*			GetActorBase();
		TESRace*		GetRace();
		bool			IsBeingRidden();
		bool			IsCommandedActor() const;
		bool			IsEssential() const;
		bool			IsGuard() const;
		bool			IsInKillMove() const;
		bool			IsAIEnabled() const;
		bool			IsOnMount();
		bool			IsPlayerTeammate() const;
		bool			IsSneaking();
		bool			IsTrespassing() const;
		void			DispelWornItemEnchantments();
		void			SendStealAlarm(TESObjectREFR* a_refItemOrContainer, TESForm* a_stolenItem, UInt32 a_numItems, UInt32 a_value, TESForm* a_owner, bool a_unk);
		SInt32			CalcEntryValue(InventoryEntryData* a_entryData, UInt32 a_numItems, bool a_unk);
		SInt32			GetDetectionLevel(Actor* a_target, UInt32 a_flag);
		bool			IsGhost();
		bool			IsSummoned();


		// members
		Flags1					flags1;			// 0E0
		float					unk0E4;			// 0E4
		UInt32					unk0E8;			// 0E8
		UInt32					pad0EC;			// 0EC
		ActorProcessManager*	processManager;	// 0F0
		UInt32					unk0F8;			// 0F8
		UInt32					unk0FC;			// 0FC
		UInt32					unk100;			// 100
		UInt32					unk104;			// 104
		float					unk108;			// 108 - init'd to -1
		UInt32					unk10C;			// 10C
		UInt32					unk110;			// 110
		UInt32					unk114;			// 114
		UInt32					unk118;			// 118
		UInt32					unk11C;			// 11C
		float					unk120;			// 120
		float					unk124;			// 124
		float					unk128;			// 128
		UInt32					unk12C;			// 12C
		UInt64					unk130;			// 130
		UInt64					unk138;			// 138
		void*					unk140;			// 140 - ActorMover*
		void*					unk148;			// 148 - MovementControllerNPC*
		UInt64					unk150;			// 150
		UInt64					unk158;			// 158
		UInt64					unk160;			// 160
		float					unk168;			// 168
		UInt32					unk16C;			// 16C
		UInt32					unk170;			// 170
		UInt32					unk174;			// 174 - init'd to 50
		UInt32					unk178;			// 178
		UInt32					unk17C;			// 17C - init'd to 7FFFFFFF
		UInt64					unk180;			// 180
		::Actor::SpellArray		addedSpells;	// 188
		void*					unk1A0;			// 1A0 - ActorMagicCaster*
		void*					unk1A8;			// 1A8 - ActorMagicCaster*
		UInt64					unk1B0;			// 1B0
		void*					unk1B8;			// 1B8 - ActorMagicCaster*
		SpellItem*				leftHandSpell;	// 1C0
		SpellItem*				rightHandSpell;	// 1C8
		UInt64					unk1D0;			// 1D0
		UInt64					unk1D8;			// 1D8
		TESForm*				equippedShout;	// 1E0
		UInt32					unk1E8;			// 1E8
		UInt32					pad1EC;			// 1EC
		TESRace*				race;			// 1F0
		float					unk1F8;			// 1F8 - init'd to -1
		Flags2					flags2;			// 1FC
		BSString				unk200;			// 200
		BSString				unk210;			// 210
		UInt64					unk220;			// 220
		Data228					unk228;			// 228
		Data228					unk234;			// 234
		Data228					unk240;			// 240
		Data228					unk24C;			// 24C
		float					unk258;			// 258 - init'd to -1
		UInt32					unk25C;			// 25C
		UInt64					unk260;			// 260
		float					unk268;			// 268
		float					unk26C;			// 26C
		UInt32					unk270;			// 270
		UInt32					unk274;			// 274
		UInt64					unk278;			// 278
		UInt64					unk280;			// 280
		UInt64					unk288;			// 288
		UInt64					unk290;			// 290
		UInt64					unk298;			// 298
		UInt64					unk2A0;			// 2A0
		UInt64					unk2A8;			// 2A8

	private:
		typedef void _DispelWornItemEnchantments_t(Actor* a_this);
		static RelocAddr<_DispelWornItemEnchantments_t*> _DispelWornItemEnchantments;

		typedef void _SendStealAlarm_t(Actor* a_this, TESObjectREFR* a_refItemOrContainer, TESForm* a_stolenItem, UInt32 a_numItems, UInt32 a_value, TESForm* a_owner, bool a_unk);
		static RelocAddr<_SendStealAlarm_t*> _SendStealAlarm;

		typedef SInt32 _CalcEntryValue_t(Actor* a_this, InventoryEntryData* a_entryData, UInt32 a_numItems, bool a_unk);
		static RelocAddr<_CalcEntryValue_t*> _CalcEntryValue;

		typedef SInt32 _GetDetectionLevel_t(Actor* a_this, Actor* a_target, UInt32 a_flag);
		static RelocAddr<_GetDetectionLevel_t*> _GetDetectionLevel;

		typedef bool _IsGhost_t(Actor* a_this);
		static RelocAddr<_IsGhost_t*> _IsGhost;
	};
	STATIC_ASSERT(offsetof(Actor, addedSpells) == 0x188);
	STATIC_ASSERT(sizeof(Actor) == 0x2B0);
}
