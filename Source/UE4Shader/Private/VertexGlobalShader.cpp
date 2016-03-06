// Fill out your copyright notice in the Description page of Project Settings.

#include "UE4Shader.h"
#include "VertexGlobalShader.h"

FVertexGlobalShader::FVertexGlobalShader(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
	: FGlobalShader(Initializer)
{
}

/**
@note �V�F�[�_�t�@�C������ "VertexGlobalShader" (.usf�t�@�C�����A�t�@�C����Engine/Shaders/�ȉ��փR�s�[���Ă���)
@note �R�[�������V�F�[�_�֐����� "Main"
*/
IMPLEMENT_SHADER_TYPE(, FVertexGlobalShader, TEXT("VertexGlobalShader"), TEXT("Main"), SF_Vertex);