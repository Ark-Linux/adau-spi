AUX_SOURCE_DIRECTORY(. src_files)

INCLUDE_DIRECTORIES(./)


ADD_EXECUTABLE(dsp-ninja ${src_files})
ADD_EXECUTABLE(dsp-zepp-es ${src_files})
ADD_EXECUTABLE(dsp-smps-es ${src_files})

TARGET_INCLUDE_DIRECTORIES(dsp-ninja PRIVATE
			 ../board/ninja)

TARGET_INCLUDE_DIRECTORIES(dsp-zepp-es PRIVATE
			 ../board/zepp-es)

TARGET_INCLUDE_DIRECTORIES(dsp-smps-es PRIVATE
			 ../board/smps-es)

INSTALL(TARGETS dsp-ninja dsp-zepp-es dsp-smps-es
	RUNTIME DESTINATION bin
)
