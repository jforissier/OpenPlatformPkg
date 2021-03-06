/** @file
*
*  Copyright (c) 2015, Hisilicon Limited. All rights reserved.
*  Copyright (c) 2015, Linaro Limited. All rights reserved.
*
*  This program and the accompanying materials
*  are licensed and made available under the terms and conditions of the BSD License
*  which accompanies this distribution.  The full text of the license may be found at
*  http://opensource.org/licenses/bsd-license.php
*
*  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
*  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
*
**/


#ifndef _SPI_FLASH_PROTOCOL_H_
#define _SPI_FLASH_PROTOCOL_H_

typedef struct _SPI_FLASH_PROTOCOL SPI_FLASH_PROTOCOL;

typedef 
EFI_STATUS
(EFIAPI *SPI_FLASH_ERASE_INTERFACE) (
    IN SPI_FLASH_PROTOCOL   *This,
    IN UINT32                  Offset,
    IN UINT32                  ulLength
    );

typedef 
EFI_STATUS
(EFIAPI *SPI_FLASH_WRITE_INTERFACE) (
    IN SPI_FLASH_PROTOCOL  *This,
    IN  UINT32                 Offset,
    IN  UINT8                 *Buffer,
    IN  UINT32                 ulLength
    );

typedef 
EFI_STATUS
(EFIAPI *SPI_FLASH_READ_INTERFACE) (
    IN SPI_FLASH_PROTOCOL   *This,
    IN UINT32                  Offset,
    IN OUT UINT8              *Buffer,
    IN UINT32                  ulLength
    );

typedef 
EFI_STATUS
(EFIAPI *SPI_FLASH_ERASE_WRITE_INTERFACE) (
    IN SPI_FLASH_PROTOCOL  *This,
    IN  UINT32                 Offset,
    IN  UINT8                 *Buffer,
    IN  UINT32                 ulLength
    );

struct _SPI_FLASH_PROTOCOL {
    SPI_FLASH_ERASE_INTERFACE             Erase;
    SPI_FLASH_WRITE_INTERFACE             Write;
    SPI_FLASH_READ_INTERFACE              Read;
    SPI_FLASH_ERASE_WRITE_INTERFACE       EraseWrite;
};

extern EFI_GUID gSpiFlashProtocolGuid;

#endif
