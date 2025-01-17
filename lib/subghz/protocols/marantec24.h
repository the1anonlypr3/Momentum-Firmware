#pragma once

#include "base.h"

#define SUBGHZ_PROTOCOL_MARANTEC24_NAME "Marantec24"

typedef struct SubGhzProtocolDecoderMarantec24 SubGhzProtocolDecoderMarantec24;
typedef struct SubGhzProtocolEncoderMarantec24 SubGhzProtocolEncoderMarantec24;

extern const SubGhzProtocolDecoder subghz_protocol_marantec24_decoder;
extern const SubGhzProtocolEncoder subghz_protocol_marantec24_encoder;
extern const SubGhzProtocol subghz_protocol_marantec24;

/**
 * Allocate SubGhzProtocolEncoderMarantec24.
 * @param environment Pointer to a SubGhzEnvironment instance
 * @return SubGhzProtocolEncoderMarantec24* pointer to a SubGhzProtocolEncoderMarantec24 instance
 */
void* subghz_protocol_encoder_marantec24_alloc(SubGhzEnvironment* environment);

/**
 * Free SubGhzProtocolEncoderMarantec24.
 * @param context Pointer to a SubGhzProtocolEncoderMarantec24 instance
 */
void subghz_protocol_encoder_marantec24_free(void* context);

/**
 * Deserialize and generating an upload to send.
 * @param context Pointer to a SubGhzProtocolEncoderMarantec24 instance
 * @param flipper_format Pointer to a FlipperFormat instance
 * @return status
 */
SubGhzProtocolStatus
    subghz_protocol_encoder_marantec24_deserialize(void* context, FlipperFormat* flipper_format);

/**
 * Forced transmission stop.
 * @param context Pointer to a SubGhzProtocolEncoderMarantec24 instance
 */
void subghz_protocol_encoder_marantec24_stop(void* context);

/**
 * Getting the level and duration of the upload to be loaded into DMA.
 * @param context Pointer to a SubGhzProtocolEncoderMarantec24 instance
 * @return LevelDuration 
 */
LevelDuration subghz_protocol_encoder_marantec24_yield(void* context);

/**
 * Allocate SubGhzProtocolDecoderMarantec24.
 * @param environment Pointer to a SubGhzEnvironment instance
 * @return SubGhzProtocolDecoderMarantec24* pointer to a SubGhzProtocolDecoderMarantec24 instance
 */
void* subghz_protocol_decoder_marantec24_alloc(SubGhzEnvironment* environment);

/**
 * Free SubGhzProtocolDecoderMarantec24.
 * @param context Pointer to a SubGhzProtocolDecoderMarantec24 instance
 */
void subghz_protocol_decoder_marantec24_free(void* context);

/**
 * Reset decoder SubGhzProtocolDecoderMarantec24.
 * @param context Pointer to a SubGhzProtocolDecoderMarantec24 instance
 */
void subghz_protocol_decoder_marantec24_reset(void* context);

/**
 * Parse a raw sequence of levels and durations received from the air.
 * @param context Pointer to a SubGhzProtocolDecoderMarantec24 instance
 * @param level Signal level true-high false-low
 * @param duration Duration of this level in, us
 */
void subghz_protocol_decoder_marantec24_feed(void* context, bool level, uint32_t duration);

/**
 * Getting the hash sum of the last randomly received parcel.
 * @param context Pointer to a SubGhzProtocolDecoderMarantec24 instance
 * @return hash Hash sum
 */
uint32_t subghz_protocol_decoder_marantec24_get_hash_data(void* context);

/**
 * Serialize data SubGhzProtocolDecoderMarantec24.
 * @param context Pointer to a SubGhzProtocolDecoderMarantec24 instance
 * @param flipper_format Pointer to a FlipperFormat instance
 * @param preset The modulation on which the signal was received, SubGhzRadioPreset
 * @return status
 */
SubGhzProtocolStatus subghz_protocol_decoder_marantec24_serialize(
    void* context,
    FlipperFormat* flipper_format,
    SubGhzRadioPreset* preset);

/**
 * Deserialize data SubGhzProtocolDecoderMarantec24.
 * @param context Pointer to a SubGhzProtocolDecoderMarantec24 instance
 * @param flipper_format Pointer to a FlipperFormat instance
 * @return status
 */
SubGhzProtocolStatus
    subghz_protocol_decoder_marantec24_deserialize(void* context, FlipperFormat* flipper_format);

/**
 * Getting a textual representation of the received data.
 * @param context Pointer to a SubGhzProtocolDecoderMarantec24 instance
 * @param output Resulting text
 */
void subghz_protocol_decoder_marantec24_get_string(void* context, FuriString* output);
