#include "OBSApi.h"
#include "API.h"
#include "CLRHostApi.h"
#include "OBSUtils.h"

using namespace System::Runtime::InteropServices;

namespace CLROBS
{
    void API::AddSettingsPane(SettingsPane^ settingsPane)
    {
        System::IntPtr unkRef =
            Marshal::GetIUnknownForObject(settingsPane);
        CLRObjectRef objectRef(unkRef.ToPointer(), nullptr);
        clrHostApi->AddSettingsPane(objectRef);
    }

    void API::AddImageSourceFactory(ImageSourceFactory^ imageSourceFactory)
    {
        System::IntPtr unkRef =
            Marshal::GetIUnknownForObject(imageSourceFactory);
        CLRObjectRef objectRef(unkRef.ToPointer(), nullptr);
        clrHostApi->AddImageSourceFactory(objectRef);
    }

    System::IntPtr
        API::GetMainWindowHandle()
    {
            return System::IntPtr(::API->GetMainWindow());
        }

    void API::Log(
        System::String^ format,
        ...array<System::Object^> ^arguments)
    {
        System::String ^formattedString =
            System::String::Format(format, arguments);
        ::Log(L"CLRHost:: %s", ToWString(formattedString).c_str());
    }

    System::String^ API::GetPluginDataPath()
    {
        return gcnew System::String(OBSGetPluginDataPath().Array());
    }

    void API::SetChangedSettings(
        bool isChanged)
    {
        ::API->SetChangedSettings(isChanged);
    }

    int API::GetMaxFPS()
    {
        return ::API->GetMaxFPS();
    }
	void API::StartStopRecording()
	{
		 ::API->StartStopRecording();
	}
	bool API::GetRecording()
	{
		return ::API->GetRecording();
	}
	System::String^ API::GetLastOutputFile()
	{
		return gcnew System::String(::API->GetLastOutputFile().Array());
	}
	void API::SetSourceRender(System::String^ name, bool render)
	{
		::API->SetSourceRender(ToWString(name).c_str(), render);
	}
	void API::SetFullscreen(bool fullscreen)
	{
		::API->SetFullscreen(fullscreen);
	}

	void API::StartStopRecordingReplayBuffer()
	{
		::API->StartStopRecordingReplayBuffer();
	}
}