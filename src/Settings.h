#pragma once

class Settings : public REX::TSingleton<Settings>
{
public:
	void Load()
	{
		const auto store = REX::FIniSettingStore::GetSingleton();
		store->Init(path.data(), "");

		store->Load();
		store->Save();
	}

	// members
	static constexpr auto path = R"(Data\SKSE\Plugins\po3_ClassicParalysis.ini)"sv;

	REX::TIniSetting<bool> frostSpells{ "Settings", "bFrostSpells", false };
	REX::TIniSetting<bool> paralysisSpells{ "Settings", "bParalysisSpells", true };
};
