/* Copyright (c) 2009 Nordic Semiconductor. All Rights Reserved.
 *
 * The information contained herein is property of Nordic Semiconductor ASA.
 * Terms and conditions of usage are described in detail in NORDIC
 * SEMICONDUCTOR STANDARD SOFTWARE LICENSE AGREEMENT.
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRANTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 */
 
#ifndef NRFJPROG_H
#define NRFJPROG_H

#define major_version (8) 
#define minor_version (4) 
#define micro_version (0) 


 enum NrfjprogErrorCodesType {
    
	Success										= 0,				// Requested operation (operations) were successfully completed.
    
	/* nrfjprog.exe or PC errors */
	NrfjprogError								= 1,		        // An error condition that should not occur has happened. 
														            // It is most probably a bug in nrfjprog.exe or nrfjprog.dll. 
	NrfjprogOutdatedError						= 2,				// Nrfjprog version is too old for the device 
	MemoryAllocationError						= 3,				// Memory allocation for nrfjprog failed failed.
	
	
	/* Command line input errors */
    InvalidArgumentError						= 11,				// Invalid arguments passed to the application.
    InsufficientArgumentsError					= 12,				// Needed arguments not passed to the application.
    IncompatibleArgumentsError					= 13,				// Incompatible arguments passed to the application.
    DuplicatedArgumentsError					= 14,				// The same argument has been provided twice.
	NoOperationError							= 15,				// The arguments passed do not perform a valid operation.
	UnavailableOperationBecauseProtectionError	= 16,				// The operation attempted can not be performed because either the main-ap or the ctrl-ap is not available.
	UnavailableOperationInFamilyError			= 17,				// The operation attempted can not be performed in the device because the feature is lacking in the device family.
	WrongFamilyForDeviceError					= 18,				// The --family option given with the command (or the default from nrfjprog.ini) does not match the device connected.

	/* nrfjprog.dll errors */
    NrfjprogDllNotFoundError					= 20,				// Unable to find nrfjprog.dll in the installation folder. Reinstall nrfjprog.
    NrfjprogDllLoadFailedError					= 21,				// Failed to Load nrfjprog.dll
    NrfjprogDllFunctionLoadFailedError			= 22,				// Failed to Load the functions from nrfjprog.dll
	NrfjprogDllNotImplementedError				= 23,				// Dll still does not implement this function for your device.

	/* nrfjprog.ini errors */
	NrfjprogIniNotFoundError                    = 25,				// Unable to find nrfjprog.ini in the installation folder. Reinstall nrfjprog.
	NrfjprogIniFormatError                      = 26,				// Format of nrfjprog.ini is incorrect
	
	/* JLinkARM.dll errors */
    JLinkARMDllNotFoundError					= 30,				// Unable to find install path for JLink software
	JLinkARMDllInvalidError						= 31,				// Dll found does not seem a valid dll.
	JLinkARMDllFailedToOpenError				= 32,				// Dll could not be opened.
	JLinkARMDllError							= 33,				// Dll reported error.
	JLinkARMDllTooOldError						= 34,				// Dll is too old for functionality. Install a newer version of JLinkARM.dll
 
	/* Emulator errors */
    InvalidSerialNumberError					= 40,				// Serial number provided is not among those connected.
    NoDebuggersError							= 41,				// There are no debuggers connected to the PC.
 	NotPossibleToConnectError					= 42,				// Not possible to connect to the NRF device.
	LowVoltageError								= 43,				// Low voltage detected at target device.
	
	/* General errors */
    FileNotFoundError							= 51,				// Unable to find the given file.
	InvalidHexFileError							= 52,				// File specified does not seem a valid hex file.
	FicrReadError								= 53,				// FICR read failed.
	WrongArgumentError							= 54,				// One of the arguments is wrong. Path does not exist, memory access is not aligned...
	VerifyError									= 55,				// The write verify operation failed.
	NoWritePermissionError						= 56,				// Unable to create file in the current working directory.
	NVMCOperationError							= 57,				// The flash operation in the device failed.
	FlashNotErasedError							= 58,				// A program operation failed because the area to write was not erased.
	RamIsOffError								= 59,				// The RAM area to read or write is unpowered.

	/* Warning. Will not be returned by nrfjprog but used to generate warnings. */
	FicrOperationWarning						= 100,				// FICR operation. It is important to be certain of what you do.
	UnalignedPageEraseWarning					= 101,				// Address provided with page erase is not aligned to first address of page.
	NoLogWarning								= 102,				// No log is possible because the program has no write permission in the current directory.
	UicrWriteOperationWithoutEraseWarning		= 103				// A UICR write operation is reuqested but there has not been a UICR erase.
};

#endif //NRFJPROG_H