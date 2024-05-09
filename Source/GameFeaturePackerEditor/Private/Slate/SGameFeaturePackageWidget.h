// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Model/FPatchersModeContext.h"
#include "SHotPatcherWidgetBase.h"
#include "GameFeature/FGameFeaturePackagerSettings.h"

// engine header
#include "Templates/SharedPointer.h"
#include "IStructureDetailsView.h"

/**
 * Implements the cooked platforms panel.
 */
class SGameFeaturePackageWidget
	: public SHotPatcherWidgetInterface
{
public:

	SLATE_BEGIN_ARGS(SGameFeaturePackageWidget) { }
	SLATE_END_ARGS()

public:

	/**
	 * Constructs the widget.
	 *
	 * @param InArgs The Slate argument list.
	 */
	void Construct(	const FArguments& InArgs,TSharedPtr<FHotPatcherModContextBase> InCreateModel);

public:
	virtual void ImportConfig()override;
	virtual void ImportProjectConfig()override{};
	virtual void ExportConfig()const override;
	virtual void ResetConfig() override;
	virtual void DoGenerate() override;
	
	virtual FGameFeaturePackagerSettings* GetConfigSettings() override{return GameFeaturePackagerSettings.Get();};
	virtual FGameFeaturePackagerSettings* GetConfigSettings()const {return GameFeaturePackagerSettings.Get();};
	
	virtual FString GetMissionName() override{return TEXT("Game Feature Packager");}
	virtual FText GetGenerateTooltipText() const override;
protected:
	void CreateExportFilterListView();
	bool CanGameFeaturePackager()const;
	bool HasValidConfig()const;
	FReply DoGameFeaturePackager();
	void FeaturePackager();

	// for context
	void SetContext(TSharedPtr<FHotPatcherModContextBase> InContext){ mContext = InContext;}
private:

	// TSharedPtr<FHotPatcherCreatePatchModel> mCreatePatchModel;
	TSharedPtr<FExportPatchSettings> PatchSettings;
	/** Settings view ui element ptr */
	TSharedPtr<IStructureDetailsView> SettingsView;
	TSharedPtr<FGameFeaturePackagerSettings> GameFeaturePackagerSettings;
	TSharedPtr<FHotPatcherModContextBase> mContext;
};

