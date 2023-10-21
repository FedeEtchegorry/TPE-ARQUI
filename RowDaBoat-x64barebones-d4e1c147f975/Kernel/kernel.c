#include <stdint.h>
#include <string.h>

#include <lib.h>
#include <moduleLoader.h>
#include <naiveConsole.h>
#include <idtLoader.h>
#include <videoDriver.h>

extern uint8_t text;
extern uint8_t rodata;
extern uint8_t data;
extern uint8_t bss;
extern uint8_t endOfKernelBinary;
extern uint8_t endOfKernel;

static const uint64_t PageSize = 0x1000;

static void * const sampleCodeModuleAddress = (void*)0x400000;
static void * const sampleDataModuleAddress = (void*)0x500000;

typedef int (*EntryPoint)();

typedef struct {
    uint16_t ModeAttributes;
    uint8_t WinAAttributes;
    uint8_t WinBAttributes;
    uint16_t WinGranularity;
    uint16_t WinSize;
    uint16_t WinASegment;
    uint16_t WinBSegment;
    uint32_t WinFuncPtr;
    uint16_t BytesPerScanLine;
    uint16_t XResolution;
    uint16_t YResolution;
    uint8_t XCharSize;
    uint8_t YCharSize;
    uint8_t NumberOfPlanes;
    uint8_t BitsPerPixel;
    uint8_t NumberOfBanks;
    uint8_t MemoryModel;
    uint8_t BankSize;
    uint8_t NumberOfImagePages;
    uint8_t Reserved_page;
    uint8_t RedMaskSize;
    uint8_t RedFieldPosition;
    uint8_t GreenMaskSize;
    uint8_t GreenFieldPosition;
    uint8_t BlueMaskSize;
    uint8_t BlueFieldPosition;
    uint8_t ReservedMaskSize;
    uint8_t ReservedFieldPosition;
    uint8_t DirectColorModeInfo;
    uint32_t PhysicalBasePtr;
    uint32_t OffScreenMemOffset;
    uint16_t OffScreenMemSize;
    uint8_t Reserved[206];
} VBE_ModeInfoBlock;

void clearBSS(void * bssAddress, uint64_t bssSize)
{
	memset(bssAddress, 0, bssSize);
}

void * getStackBase()
{
	return (void*)(
		(uint64_t)&endOfKernel
		+ PageSize * 8				//The size of the stack itself, 32KiB
		- sizeof(uint64_t)			//Begin at the top of the stack
	);
}

void * initializeKernelBinary()
{
	char buffer[10];

	ncPrint("[x64BareBones]");
	ncNewline();

	ncPrint("CPU Vendor:");
	ncPrint(cpuVendor(buffer));
	ncNewline();

	ncPrint("[Loading modules]");
	ncNewline();
	void * moduleAddresses[] = {
		sampleCodeModuleAddress,
		sampleDataModuleAddress
	};

	loadModules(&endOfKernelBinary, moduleAddresses);
	ncPrint("[Done]");
	ncNewline();
	ncNewline();

	ncPrint("[Initializing kernel's binary]");
	ncNewline();

	clearBSS(&bss, &endOfKernel - &bss);

	ncPrint("  text: 0x");
	ncPrintHex((uint64_t)&text);
	ncNewline();
	ncPrint("  rodata: 0x");
	ncPrintHex((uint64_t)&rodata);
	ncNewline();
	ncPrint("  data: 0x");
	ncPrintHex((uint64_t)&data);
	ncNewline();
	ncPrint("  bss: 0x");
	ncPrintHex((uint64_t)&bss);
	ncNewline();

	ncPrint("[Done]");
	ncNewline();
	ncNewline();
	return getStackBase();
}

int main(){


	// ncPrint("[Kernel Main]");
	// ncNewline();
	// ncPrint("  Sample code module at 0x");
	// ncPrintHex((uint64_t)sampleCodeModuleAddress);
	// ncNewline();
	// ncPrint("  Calling the sample code module returned: ");
	// ncPrintHex(((EntryPoint)sampleCodeModuleAddress)());
	// ncNewline();
	// ncNewline();

	// ncPrint("  Sample data module at 0x");
	// ncPrintHex((uint64_t)sampleDataModuleAddress);
	// ncNewline();
	// ncPrint("  Sample data module contents: ");
	// ncPrint((char*)sampleDataModuleAddress);
	// ncNewline();

	// ncPrint("[Finished]");
	load_idt();
	script();
char* array="URNA IACULIS UT MORBI FACILISI AUGUE. PARTURIENT FINIBUS BLANDIT RISUS PER IACULIS AUCTOR ULLAMCORPER PHASELLUS ARCU. ARCU FUSCE ULTRICIES EUISMOD ETIAM INTEGER CRAS AD PEDE IMPERDIET.";
printText(array, 0x000000ff, 0xffffff);
char* array2= "NO LES FALTAN AGALLAS A LOS 300 ESPARTANOS DE LAS TERMOPILAS";
printText(array2, 0x00ffffff, 0x00000000);
    //fillScreen(0x00fafafa);
	while(1);
	return 0;
}
