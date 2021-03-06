#pragma once

#include <vector>  // vector
#include <string>  // string

#include "json.hpp"  // json
#include "Utility.h"  // boolToString


namespace QuickLootRE
{
	class ISetting
	{
	public:
		ISetting(std::string a_key) : _key(a_key) {}
		virtual ~ISetting() {}

		virtual	void				Assign(void* a_val)			= 0;
		virtual void				Dump()						= 0;
		inline const std::string&	key()				const	{ return _key; };

	protected:
		std::string	_key;
	};


	static std::vector<ISetting*> settings;


	class bSetting : public ISetting
	{
	public:
		bSetting(std::string a_key, bool a_value) : ISetting(a_key), _value(a_value) { settings.push_back(this); }
		virtual ~bSetting() {}

		virtual void	Assign(void* a_val)			override	{ _value = *((bool*)a_val); }
		virtual void	Dump()						override	{ _DMESSAGE("%s: %s", _key.c_str(), boolToString(_value).c_str()); }
		inline			operator bool()		const				{ return _value; }

	protected:
		bool _value;
	};


	class iSetting : public ISetting
	{
	public:
		iSetting(std::string a_key, SInt32 a_value) : ISetting(a_key), _value(a_value) { settings.push_back(this); }
		virtual ~iSetting() {}

		virtual void	Assign(void* a_val)			override	{ _value = *((SInt32*)a_val); }
		virtual void	Dump()						override	{ _DMESSAGE("%s: %i", _key.c_str(), _value); }
		inline			operator SInt32()	const				{ return _value; }

	protected:
		SInt32 _value;
	};


	class fSetting : public ISetting
	{
	public:
		fSetting(std::string a_key, float a_value) : ISetting(a_key), _value(a_value) { settings.push_back(this); }
		virtual ~fSetting() {}

		virtual void	Assign(void* a_val)			override	{ _value = *((float*)a_val); }
		virtual void	Dump()						override	{ _DMESSAGE("%s: %f", _key.c_str(), _value); }
		inline			operator float()	const				{ return _value; }

	protected:
		float _value;
	};


	class aSetting : public ISetting
	{
	public:
		aSetting(std::string a_key, std::initializer_list<std::string> a_list = {}) : ISetting(a_key), _values(a_list) { settings.push_back(this); }
		virtual ~aSetting() {}

		virtual void Assign(void* a_val) override
		{
			_values.clear();
			using nlohmann::json;
			json jArr = *((json*)a_val);
			for (auto& val : jArr) {
				_values.emplace_back(val.get<std::string>());
			}
		}
		virtual void Dump() override
		{
			_DMESSAGE("%s:", _key.c_str());
			for (auto& val : _values) {
				_DMESSAGE("\t%s", val.c_str());
			}
		}
		inline std::vector<std::string>::iterator	begin()	noexcept	{ return _values.begin(); }
		inline std::vector<std::string>::iterator	end()	noexcept	{ return _values.end(); }

	protected:
		std::vector<std::string> _values;
	};


	class Settings
	{
	public:
		static void		loadSettings();
		static void		dump();


		static bSetting	disableInCombat;
		static bSetting	disableTheft;
		static bSetting	disablePickPocketing;
		static bSetting	disableIfEmpty;
		static bSetting	disableSingleLoot;
		static bSetting	playAnimations;
		static iSetting	itemLimit;
		static fSetting	scale;
		static fSetting	positionX;
		static fSetting	positionY;
		static fSetting	opacity;
		static aSetting	sortOrder;

		static bool		isApplied;

	private:
		Settings() {}
		~Settings() {}


		static const char* FILE_NAME;
	};
}
