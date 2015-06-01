#include "OBSApi.h"


void COBSEnterSceneMutex() { API->EnterSceneMutex(); }
void COBSLeaveSceneMutex() { API->LeaveSceneMutex(); }

void COBSRegisterSceneClass(CTSTR lpClassName, CTSTR lpDisplayName,
	OBSCREATEPROC createProc, OBSCONFIGPROC configProc)
{
	API->RegisterSceneClass(lpClassName, lpDisplayName, createProc, configProc);
}

void COBSRegisterImageSourceClass(CTSTR lpClassName, CTSTR lpDisplayName, OBSCREATEPROC createProc, OBSCONFIGPROC configProc)
{
	API->RegisterImageSourceClass(lpClassName, lpDisplayName, createProc, configProc);
}

ImageSource* COBSCreateImageSource(CTSTR lpClassName, XElement *data)
{
	return API->CreateImageSource(lpClassName, data);
}

XElement* COBSGetSceneListElement()
{
	return API->GetSceneListElement();
}

XElement* COBSGetGlobalSourceListElement()
{
	return API->GetGlobalSourceListElement();
}

bool COBSSetScene(CTSTR lpScene, bool bPost)
{
	return API->SetScene(lpScene, bPost);
}

Scene* COBSGetScene()            { return API->GetScene(); }

CTSTR COBSGetSceneName()         { return API->GetSceneName(); }
XElement* COBSGetSceneElement()  { return API->GetSceneElement(); }

void COBSDisableTransitions()    { API->DisableTransitions(); }
void COBSEnableTransitions()     { API->EnableTransitions(); }
bool COBSTransitionsEnabled()    { return API->TransitionsEnabled(); }

bool COBSSetSceneCollection(CTSTR lpCollection, CTSTR lpScene)
{
	return API->SetSceneCollection(lpCollection, lpScene);
}

CTSTR COBSGetSceneCollectionName()                   { return API->GetSceneCollectionName(); }
void COBSGetSceneCollectionNames(StringList &list)   { API->GetSceneCollectionNames(list); }

//low-order word is VK, high-order word is modifier.  equivalent to the value given by hotkey controls
UINT COBSCreateHotkey(DWORD hotkey, OBSHOTKEYPROC hotkeyProc, UPARAM param)
{
	return API->CreateHotkey(hotkey, hotkeyProc, param);
}

void COBSDeleteHotkey(UINT hotkeyID)
{
	API->DeleteHotkey(hotkeyID);
}

Vect2 COBSGetBaseSize()          { return API->GetBaseSize(); }
Vect2 COBSGetRenderFrameSize()   { return API->GetRenderFrameSize(); }
Vect2 COBSGetOutputSize()        { return API->GetOutputSize(); }

void COBSGetRenderFrameOffset(UINT &x, UINT &y)                  { API->GetRenderFrameOffset(x, y); }
void COBSGetRenderFrameControlSize(UINT &width, UINT &height)    { API->GetRenderFrameControlSize(width, height); }
UINT COBSGetMaxFPS()                                             { return API->GetMaxFPS(); }
bool COBSGetRenderFrameIn1To1Mode()                              { return API->GetRenderFrameIn1To1Mode(); }
UINT COBSGetCaptureFPS()                                         { return API->GetCaptureFPS(); }
UINT COBSGetTotalFrames()                                        { return API->GetTotalFrames(); }
UINT COBSGetFramesDropped()                                      { return API->GetFramesDropped(); }

CTSTR COBSGetLanguage()          { return API->GetLanguage(); }

HWND COBSGetMainWindow()         { return API->GetMainWindow(); }

CTSTR COBSGetAppDataPath()       { return API->GetAppDataPath(); }
String COBSGetPluginDataPath()   { return API->GetPluginDataPath(); }

UINT COBSAddStreamInfo(CTSTR lpInfo, StreamInfoPriority priority)            { return API->AddStreamInfo(lpInfo, priority); }
void COBSSetStreamInfo(UINT infoID, CTSTR lpInfo)                            { API->SetStreamInfo(infoID, lpInfo); }
void COBSSetStreamInfoPriority(UINT infoID, StreamInfoPriority priority)     { API->SetStreamInfoPriority(infoID, priority); }
void COBSRemoveStreamInfo(UINT infoID)                                       { API->RemoveStreamInfo(infoID); }

UINT COBSGetTotalStreamTime()    { return API->GetTotalStreamTime(); }
UINT COBSGetBytesPerSec()        { return API->GetBytesPerSec(); }

bool COBSUseMultithreadedOptimizations()         { return API->UseMultithreadedOptimizations(); }

void COBSAddAudioSource(AudioSource *source)     { API->AddAudioSource(source); }
void COBSRemoveAudioSource(AudioSource *source)  { API->RemoveAudioSource(source); }

QWORD COBSGetAudioTime()         { return API->GetAudioTime(); }

CTSTR COBSGetAppPath()           { return API->GetAppPath(); }

void COBSStartStopStream()       { API->StartStopStream(); }
void COBSStartStopPreview()      { API->StartStopPreview(); }
void COBSStartStopRecording()    { API->StartStopRecording(); }
bool COBSGetStreaming()          { return API->GetStreaming(); }
bool COBSGetPreviewOnly()        { return API->GetPreviewOnly(); }
bool COBSGetRecording()          { return API->GetRecording(); }

bool COBSGetKeepRecording()      { return API->GetKeepRecording(); }

void COBSStartStopRecordingReplayBuffer() { API->StartStopRecordingReplayBuffer(); }
bool COBSGetRecordingReplayBuffer()       { return API->GetRecordingReplayBuffer(); }
void COBSSaveReplayBuffer()               { API->SaveReplayBuffer(); }

void COBSSetSourceOrder(StringList &sourceNames)             { API->SetSourceOrder(sourceNames); }
void COBSSetSourceRender(CTSTR lpSource, bool render)        { API->SetSourceRender(lpSource, render); }

void COBSSetDesktopVolume(float val, bool finalValue)        { API->SetDesktopVolume(val, finalValue); }
float COBSGetDesktopVolume()                                 { return API->GetDesktopVolume(); }
void COBSToggleDesktopMute()                                 { API->ToggleDesktopMute(); }
bool COBSGetDesktopMuted()                                   { return API->GetDesktopMuted(); }

void COBSSetMicVolume(float val, bool finalValue)            { API->SetMicVolume(val, finalValue); }
float COBSGetMicVolume()                                     { return API->GetMicVolume(); }
void COBSToggleMicMute()                                     { API->ToggleMicMute(); }
bool COBSGetMicMuted()                                       { return API->GetMicMuted(); }

DWORD COBSGetVersion()                       { return API->GetOBSVersion(); }
bool COBSIsTestVersion()                     { return API->IsTestVersion(); }

UINT COBSNumAuxAudioSources()                { return API->NumAuxAudioSources(); }
AudioSource* COBSGetAuxAudioSource(UINT id)  { return API->GetAuxAudioSource(id); }

AudioSource* COBSGetDesktopAudioSource()     { return API->GetDesktopAudioSource(); }
AudioSource* COBSGetMicAudioSource()         { return API->GetMicAudioSource(); }

void COBSGetCurDesktopVolumeStats(float *rms, float *max, float *peak)   { API->GetCurDesktopVolumeStats(rms, max, peak); }
void COBSGetCurMicVolumeStats(float *rms, float *max, float *peak)       { API->GetCurMicVolumeStats(rms, max, peak); }

void COBSAddSettingsPane(SettingsPane *pane)     { API->AddSettingsPane(pane); }
void COBSRemoveSettingsPane(SettingsPane *pane)  { API->RemoveSettingsPane(pane); }

UINT COBSGetAPIVersion()                         { return 0x0103; }

UINT COBSGetSampleRateHz()                       { return API->GetSampleRateHz(); }
