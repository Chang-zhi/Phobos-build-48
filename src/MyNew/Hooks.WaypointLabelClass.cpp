// ======================================================================
//					Custom Waypoint Label Display
//					Class: WaypointLabelClass
//					Author: Chang_zhi
// ======================================================================
#include <Phobos.h>
#include <Utilities/Macro.h>
#include <MyNew/WaypointLabelClass.h>

DEFINE_HOOK(0x6D4684, TacticalClass_Render_WaypointLabels, 0x6)
{
	if (ScenarioClass::Instance && SessionClass::Instance.CurrentlyInGame)
	{
		for (const auto& pLabel : WaypointLabelClass::Array)
		{
			if (pLabel) pLabel->Draw();
		}
	}
	return 0;
}

DEFINE_HOOK(0x67B8C0, SessionClass_RestartScenario_ClearWaypointLabels, 0x6)
{
	WaypointLabelClass::ClearAll();
	return 0;
}

DEFINE_HOOK(0x685659, Scenario_ClearClasses_ClearWaypointLabels, 0xA)
{
	WaypointLabelClass::ClearAll();
	return 0;
}
