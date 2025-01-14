//
// Created by saeed on 1/14/25.
//

#ifndef LEETCODE535ENCODEANDDECODETINYURL_H
#define LEETCODE535ENCODEANDDECODETINYURL_H
#include <string>


class LeetCode535EncodeAndDecodeTinyURL {
    class Solution {
    private:
        const std::string base64_chars =
          "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
          "abcdefghijklmnopqrstuvwxyz"
          "0123456789+/";
        bool is_base64(unsigned char c) const;
    public:

        // Encodes a URL to a shortened URL.
        std::string encode(std::string longUrl);
        // Decodes a shortened URL to its original URL.
        std::string decode(std::string shortUrl);
    };
};



#endif //LEETCODE535ENCODEANDDECODETINYURL_H
