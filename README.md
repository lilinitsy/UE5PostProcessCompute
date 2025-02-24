# Compute Shader Examples
In this repo are many compute shader examples, built off some examples from Shadeup (https://dev.epicgames.com/community/learning/tutorials/WkwJ/unreal-engine-simple-compute-shader-with-cpu-readback)

## Instructions to add Shaders
### Option 1: Adding to existing Module
For this one, the .uplugin file in Plugins/ComputeShader_Plugin doesn't need to be modified, and nor does the ComputeShader.Build.cs.

- Add a new folder in Plugins/ComputeShader_Plugin/Source/Public: NewShader/
- Inside NewShader/, add NewShader.h
	- This file will define the NewShaderInterface class, the public interface so that the compute shader can be invoked. Blueprint code is also put inside here, although it can be disregarded if blueprints aren't useful.
- Add a new folder in Plugins/ComputeShader_Plugin/Source/Private: NewShader/
- Inside NewShader/, add NewShader.cpp
	- This file has parameter definitions, and the CPP code to allow for interfacing with the shader.
	- The class here will be callable from an AActor or any game code.
	- Make sure that the IMPLEMENT_GLOBAL_SHADER line modifies the shader path and function hooks.

