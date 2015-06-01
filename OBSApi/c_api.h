#pragma once
//-------------------------------------------------------------------
//C-style API exports, use these
extern "C" {
	BASE_EXPORT void COBSEnterSceneMutex();
	BASE_EXPORT void COBSLeaveSceneMutex();

	BASE_EXPORT void COBSRegisterSceneClass(CTSTR lpClassName, CTSTR lpDisplayName, OBSCREATEPROC createProc, OBSCONFIGPROC configProc);
	BASE_EXPORT void COBSRegisterImageSourceClass(CTSTR lpClassName, CTSTR lpDisplayName, OBSCREATEPROC createProc, OBSCONFIGPROC configProc);

	BASE_EXPORT ImageSource* COBSCreateImageSource(CTSTR lpClassName, XElement *data);

	BASE_EXPORT XElement* COBSGetSceneListElement();
	BASE_EXPORT XElement* COBSGetGlobalSourceListElement();

	BASE_EXPORT bool COBSSetScene(CTSTR lpScene, bool bPost);
	BASE_EXPORT Scene* COBSGetScene();

	BASE_EXPORT CTSTR COBSGetSceneName();
	BASE_EXPORT XElement* COBSGetSceneElement();

	BASE_EXPORT bool COBSSetSceneCollection(CTSTR lpCollection, CTSTR lpScene);
	BASE_EXPORT CTSTR COBSGetSceneCollectionName();
	BASE_EXPORT void COBSGetSceneCollectionNames(StringList &list);

	BASE_EXPORT void COBSDisableTransitions();
	BASE_EXPORT void COBSEnableTransitions();
	BASE_EXPORT bool COBSTransitionsEnabled();

	//low-order word is VK, high-order word is modifier.  equivalent to the value given by hotkey controls
	BASE_EXPORT UINT COBSCreateHotkey(DWORD hotkey, OBSHOTKEYPROC hotkeyProc, UPARAM param);
	BASE_EXPORT void COBSDeleteHotkey(UINT hotkeyID);

	BASE_EXPORT Vect2 COBSGetBaseSize();          //get the base scene size
	BASE_EXPORT Vect2 COBSGetRenderFrameSize();   //get the render frame size
	BASE_EXPORT Vect2 COBSGetOutputSize();        //get the stream output size
	BASE_EXPORT void COBSGetRenderFrameOffset(UINT &x, UINT &y);
	BASE_EXPORT void COBSGetRenderFrameControlSize(UINT &width, UINT &height);
	BASE_EXPORT UINT COBSGetMaxFPS();
	BASE_EXPORT bool COBSGetIn1To1Mode();
	BASE_EXPORT UINT COBSGetCaptureFPS();
	BASE_EXPORT UINT COBSGetTotalFrames();
	BASE_EXPORT UINT COBSGetFramesDropped();

	BASE_EXPORT CTSTR COBSGetLanguage();

	BASE_EXPORT HWND COBSGetMainWindow();

	BASE_EXPORT CTSTR COBSGetAppDataPath();
	BASE_EXPORT String COBSGetPluginDataPath();

	BASE_EXPORT UINT COBSAddStreamInfo(CTSTR lpInfo, StreamInfoPriority priority);
	BASE_EXPORT void COBSSetStreamInfo(UINT infoID, CTSTR lpInfo);
	BASE_EXPORT void COBSSetStreamInfoPriority(UINT infoID, StreamInfoPriority priority);
	BASE_EXPORT void COBSRemoveStreamInfo(UINT infoID);

	BASE_EXPORT UINT COBSGetTotalStreamTime();
	BASE_EXPORT UINT COBSGetBytesPerSec();

	BASE_EXPORT bool COBSUseMultithreadedOptimizations();

	BASE_EXPORT void COBSAddAudioSource(AudioSource *source);
	BASE_EXPORT void COBSRemoveAudioSource(AudioSource *source);

	BASE_EXPORT QWORD COBSGetAudioTime();

	BASE_EXPORT CTSTR COBSGetAppPath();

	BASE_EXPORT void COBSStartStopStream();
	BASE_EXPORT void COBSStartStopPreview();
	BASE_EXPORT void COBSStartStopRecording();
	BASE_EXPORT bool COBSGetStreaming();
	BASE_EXPORT bool COBSGetPreviewOnly();
	BASE_EXPORT bool COBSGetRecording();

	BASE_EXPORT bool COBSGetKeepRecording();

	BASE_EXPORT void COBSStartStopRecordingReplayBuffer();
	BASE_EXPORT bool COBSGetRecordingReplayBuffer();
	BASE_EXPORT void COBSSaveReplayBuffer();

	BASE_EXPORT void COBSSetSourceOrder(StringList &sourceNames);
	BASE_EXPORT void COBSSetSourceRender(CTSTR lpSource, bool render);

	/* Volume Calls */
	BASE_EXPORT void COBSSetMicVolume(float val, bool finalValue);
	BASE_EXPORT float COBSGetMicVolume();
	BASE_EXPORT void COBSToggleMicMute();
	BASE_EXPORT bool COBSGetMicMuted();

	BASE_EXPORT void COBSSetDesktopVolume(float val, bool finalValue);
	BASE_EXPORT float COBSGetDesktopVolume();
	BASE_EXPORT void COBSToggleDesktopMute();
	BASE_EXPORT bool COBSGetDesktopMuted();

	BASE_EXPORT DWORD COBSGetVersion();
	BASE_EXPORT bool COBSIsTestVersion();

	BASE_EXPORT UINT COBSNumAuxAudioSources();
	BASE_EXPORT AudioSource* COBSGetAuxAudioSource(UINT id);

	BASE_EXPORT AudioSource* COBSGetDesktopAudioSource();
	BASE_EXPORT AudioSource* COBSGetMicAudioSource();

	BASE_EXPORT void COBSGetCurDesktopVolumeStats(float *rms, float *max, float *peak);
	BASE_EXPORT void COBSGetCurMicVolumeStats(float *rms, float *max, float *peak);

	BASE_EXPORT void COBSAddSettingsPane(SettingsPane *pane);
	BASE_EXPORT void COBSRemoveSettingsPane(SettingsPane *pane);

	/** gets API version.  version is formatted: 0xMMmm */
	BASE_EXPORT UINT COBSGetAPIVersion();

	BASE_EXPORT UINT COBSGetSampleRateHz();

}