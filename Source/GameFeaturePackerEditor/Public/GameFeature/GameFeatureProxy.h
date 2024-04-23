#pragma once
#include "ThreadUtils/FThreadUtils.hpp"
#include "FGameFeaturePackagerSettings.h"
#include "CreatePatch/HotPatcherProxyBase.h"
#include "CreatePatch/PatcherProxy.h"
// engine header
#include "Templates/SharedPointer.h"
#include "GameFeatureProxy.generated.h"


UCLASS()
class GAMEFEATUREPACKEREDITOR_API UGameFeatureProxy:public UHotPatcherProxyBase
{
    GENERATED_BODY()
public:
    virtual bool DoExport() override;
    virtual FGameFeaturePackagerSettings* GetSettingObject()override{ return (FGameFeaturePackagerSettings*)Setting; }

protected:
    UPROPERTY()
    UPatcherProxy* PatcherProxy = nullptr;
private:
    TSharedPtr<FExportPatchSettings> PatchSettings;
    TSharedPtr<FThreadWorker> ThreadWorker;
};
