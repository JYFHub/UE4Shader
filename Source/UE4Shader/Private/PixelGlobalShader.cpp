// Fill out your copyright notice in the Description page of Project Settings.

#include "UE4Shader.h"
#include "PixelGlobalShader.h"

#include "ShaderParameterUtils.h"

/**
@brief ���j�t�H�[���o�b�t�@
*/
IMPLEMENT_UNIFORM_BUFFER_STRUCT(FPixelShaderUniformBuffer, TEXT("PSUniform"))

FPixelGlobalShader::FPixelGlobalShader(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
	: FGlobalShader(Initializer)
{
}

void FPixelGlobalShader::ModifyCompilationEnvironment(EShaderPlatform Platform, FShaderCompilerEnvironment& OutEnvironment)
{
	FGlobalShader::ModifyCompilationEnvironment(Platform, OutEnvironment);
	OutEnvironment.CompilerFlags.Add(CFLAG_StandardOptimization);
}

void FPixelGlobalShader::SetUniformBuffer(FRHICommandList& CommandList, const FPixelShaderUniformBuffer& UniformBuffer)
{
	TUniformBufferRef<FPixelShaderUniformBuffer> Buffer;
	Buffer = TUniformBufferRef<FPixelShaderUniformBuffer>::CreateUniformBufferImmediate(UniformBuffer, UniformBuffer_SingleDraw);
	SetUniformBufferParameter(CommandList, GetPixelShader(), GetUniformBufferParameter<FPixelShaderUniformBuffer>(), Buffer);
}

/**
@note �V�F�[�_�t�@�C������ "PixelGlobalShader" (.usf�t�@�C�����A�t�@�C����Engine/Shaders/�ȉ��փR�s�[���Ă���)
@note �R�[�������V�F�[�_�֐����� "Main"
*/
IMPLEMENT_SHADER_TYPE(, FPixelGlobalShader, TEXT("PixelGlobalShader"), TEXT("Main"), SF_Pixel);