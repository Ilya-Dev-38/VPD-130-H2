
For tM series modules.

Type-code (Range Type) is used to tell the API functions how to convert the binary data 
into readable value depending on the configuration of the tM modules. 

Gain can be 1, 10, 1000 ... 100000.
For example: Range= +/- 2.5V, Gain= 1000, then the value range is +/- 2500 in the TPD.

The Type-code (Range Type) and Gain can be configured in 
HMIWorks / Workspace / Tags / Device / [device] / [tag] 
==> Right-click mouse button to pop up the menu and select "Edit IO Tag".

The data format of the tM AI/AO modules must be configured as 2's complement.

Supports the following API functions.

// This function converts AI hex to long value based on tM AI type-code.
//
// id[]:     Module ID/name string. The tM-AD2/AD8/AD8C modules require this.
// typeCode: AI type-code indicates the mapping of the input and output value range.
// hexVal:   The input hex value.
// gain:     Can be 1, 10, 100, 1000, 10000, 100000.
//           For example: Gain 1000 maps the +/- 2.5 range to +/- 2500.
// *err:     0 = OK, -1=Wrong type-code, -2=Wrong gain code.
//           err can be NULL address for skipping error code.
// return:   A long value converted from hex.
long tM_AIHexToLong(char id[], uint16_t typeCode, uint16_t hexVal, int gain, int *err);

// This function converts AO hex to long value based on tM AO type-code.
//
// id[]:     Module ID/name string.
// typeCode: AO type-code indicates the mapping of the input and output value range.
// hexVal:   The input hex value.
// gain:     Can be 1, 10, 100, 1000, 10000, 100000.
//           For example: Gain 1000 maps the +/- 2.5 range to +/- 2500.
// *err:     0 = OK, -1=Wrong type-code, -2=Wrong gain code.
//           err can be NULL address for skipping error code.
// return:   A long value converted from hex.
long tM_AOHexToLong(char id[], uint16_t typeCode, uint16_t hexVal, int gain, int *err);

// This function converts AO long to hex value based on tM AO type-code.
//
// id[]:     Module ID/name string.
// typeCode: AO type-code indicates the mapping of the input and output value range.
// val:      The input long value.
// gain:     Can be 1, 10, 100, 1000, 10000, 100000.
//           For example: Gain 1000 maps the +/- 2500 range to +/- 2.5.
// *err:     0 = OK, -1=Wrong type-code, -2=Wrong gain code.
//           err can be NULL address for skipping error code.
// return:   A hex value converted from long.
uint16_t tM_AOLongToHex(char id[], uint16_t typeCode, long val, int gain, int *err);

Dec.01, 2022

