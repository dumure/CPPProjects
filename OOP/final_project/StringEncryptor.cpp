#include "StringEncryptor.h"

std::string StringEncryptor::encrypt(const std::string& a_string)
{
    std::vector<unsigned char> hash(picosha2::k_digest_size);
    picosha2::hash256(a_string.begin(), a_string.end(), hash.begin(), hash.end());

    std::string hex_str = picosha2::bytes_to_hex_string(hash.begin(), hash.end());
    return hex_str;
}