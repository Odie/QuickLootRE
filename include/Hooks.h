#pragma once

#undef PlaySound

#include "skse64_common/Relocation.h"  // RelocPtr, RelocAddr

#include "Offsets.h"

class TESForm;

namespace RE
{
	class Actor;
}


namespace Hooks
{
	typedef void _SendItemsPickPocketedEvent_t(UInt32 a_numItems);
	extern RelocAddr<_SendItemsPickPocketedEvent_t*> _SendItemsPickPocketedEvent;

	typedef UInt32 _GetPickPocketChance_t(float a_playerSkill, float a_targetSkill, UInt32 a_totalValue, float a_totalWeight, RE::Actor* a_player, RE::Actor* a_target, bool a_isDetected, TESForm* a_item);
	extern RelocAddr<_GetPickPocketChance_t*> _GetPickPocketChance;

	void installHooks();
}
