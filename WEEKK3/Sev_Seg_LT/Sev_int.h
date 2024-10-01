/*
 * Sev_int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: nada8
 */

#ifndef SEV_INT_H_
#define SEV_INT_H_

//#include "Sev_config.h"

ES_t Sev_Seg_enuInit(SEG_t *copy_SegConfig);
ES_t Sev_Seg_enuDisplayNum(u8 copy_SegID,u8 copy_u8Num);
ES_t Sev_Seg_enuClearDisplay(u8 copy_SegID);
ES_t Sev_Seg_enuEnableCommon(u8 copy_SegID);
ES_t Sev_Seg_enuDisableCommon(u8 copy_SegID);
ES_t Sev_Seg_enuEnableDOT(u8 copy_SegID);
ES_t Sev_Seg_enuDisableDOT(u8 copy_SegID);

#endif /* SEV_INT_H_ */
