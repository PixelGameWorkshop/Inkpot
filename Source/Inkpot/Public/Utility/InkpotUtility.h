#pragma once 

#include "CoreMinimal.h"

namespace InkpotUtil
{
	INKPOT_API const FString* GetTag(const TArray<FString>& Tags, const FString& Tag)
	{
		for (const FString& tag : Tags)
			if (tag.StartsWith(Tag))
				return &tag;
		return nullptr;
	}

	template<typename T>
	INKPOT_API bool GetValue(const TArray<FString>& Tags, const FString& Tag, T& Out)
	{
		const FString* tag = GetTag(Tags, Tag);
		if (!tag)
			return false;
		const TCHAR* ptr = **tag;
		FParse::Value(ptr, *Tag, Out);
		return true;
	}
}