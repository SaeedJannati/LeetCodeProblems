//
// Created by saeed on 1/14/25.
//

#include "LeetCode535EncodeAndDecodeTinyURL.h"
#include <iostream>
#include <string>

bool LeetCode535EncodeAndDecodeTinyURL::Solution::is_base64(unsigned char c) const {
    return (isalnum(c) || (c == '+') || (c == '/'));
}

std::string LeetCode535EncodeAndDecodeTinyURL::Solution::encode(std::string longUrl) {
    std::string encoded;
    size_t i = 0;
    unsigned char char_array_3[3];
    unsigned char char_array_4[4];

    for (unsigned char c : longUrl) {
        char_array_3[i++] = c;
        if (i == 3) {
            char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
            char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
            char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
            char_array_4[3] = char_array_3[2] & 0x3f;

            for (i = 0; i < 4; ++i) {
                encoded += base64_chars[char_array_4[i]];
            }
            i = 0;
        }
    }

    if (i) {
        for (size_t j = i; j < 3; ++j) {
            char_array_3[j] = '\0';
        }

        char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
        char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
        char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
        char_array_4[3] = char_array_3[2] & 0x3f;

        for (size_t j = 0; j < i + 1; ++j) {
            encoded += base64_chars[char_array_4[j]];
        }

        while ((i++ < 3)) {
            encoded += '=';
        }
    }

    return encoded;
}

std::string LeetCode535EncodeAndDecodeTinyURL::Solution::decode(std::string shortUrl) {
    int in_len = shortUrl.size();
    int i = 0;
    int j = 0;
    int in_ = 0;
    unsigned char char_array_4[4], char_array_3[3];
    std::string decoded;

    while (in_len-- && (shortUrl[in_] != '=') && is_base64(shortUrl[in_])) {
        char_array_4[i++] = shortUrl[in_++];
        if (i == 4) {
            for (i = 0; i < 4; ++i) {
                char_array_4[i] = base64_chars.find(char_array_4[i]);
            }

            char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
            char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
            char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

            for (i = 0; i < 3; ++i) {
                decoded += char_array_3[i];
            }
            i = 0;
        }
    }

    if (i) {
        for (j = i; j < 4; ++j) {
            char_array_4[j] = 0;
        }

        for (j = 0; j < 4; ++j) {
            char_array_4[j] = base64_chars.find(char_array_4[j]);
        }

        char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
        char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
        char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

        for (j = 0; j < i - 1; ++j) {
            decoded += char_array_3[j];
        }
    }

    return decoded;
}
