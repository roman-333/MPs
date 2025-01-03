
#include "functions.hpp"

#include <cctype>
#include <iostream>
#include <stdexcept>
#include <vector>

/**
 * TODO: Implement this function
 * @param word word to change to lowercase
 * @return result of changing every character in word to lowercase
 */
std::string StringToLower(const std::string& word) {
  std::cout << "Input to StringToLower() : " << word << std::endl;

  std::string word2 = word;
  std::string lower_word;
/*
  for (char i : word2) {
    lower_word += std::tolower(i);
  }
  return lower_word;
}
*/
  for (unsigned int i = 0; i < word2.length(); i++) {
    lower_word += static_cast<char>(std::tolower(static_cast<unsigned char>(word2[i])));
  }
  return lower_word;
}


/**
 * TODO: Implement this function
 * @param v1 first character in potential vowel group
 * @param v2 second character in potential vowel group
 * @return true if v1 and v2 form a valid vowel group
 */
bool IsVowelGroup(const char& v1, const char& v2) {
  std::cout << "Input to IsVowelGroup() : \"" << v1 << "\" \"" << v2 << "\""
            << std::endl;
  std::vector<char> vaild_second{'i', 'u'};
  if (IsVowel(v1) && IsVowel(v2) && v2 != 'a') {
    if (v1 == 'a' && IsVowel(v2)) {
      return true;
    }
    if (v1 == 'e' && (v2 == vaild_second[0] || v2 == vaild_second[1])) {
      return true;
    }
    if (v1 == 'i' && v2 == vaild_second[1]) {
      return true;
    }
    if (v1 == 'o' && (v2 == vaild_second[0] || v2 == vaild_second[1])) {
      return true;
    }
    if (v1 == 'u' && v2 == 'i') {
      return true;
    }
  }

  return false;
}

/**
 * TODO: Complete this function
 * @param v potential vowel character
 * @return true if v is a vowel
 */
bool IsVowel(const char& v) {
  std::cout << "Input to IsVowel() : \"" << v << "\"" << std::endl;

  std::vector<char> valid_char{'a', 'e', 'i', 'o', 'u'};
  for (unsigned int i = 0; i < valid_char.size(); i++) {
    if (valid_char[i] == v) {
      return true;
    }
  }
  return false;
}

/**
 * TODO: Complete this function
 * @param c potential consonant character
 * @return true if c is a consonant
 */
bool IsConsonant(const char& c) {
  std::cout << "Input to IsConsonant() : \"" << c << "\"" << std::endl;
  std::vector<char> vec_consonant{'p', 'k', 'h', 'l', 'm', 'n', 'w'};
  for (char i : vec_consonant) {
    if (c == i) {
      return true;
    }
  }
  return false;
}

/**
 * TODO: Implement this function
 * @param c character to check validity of
 * @return true if input c is a valid character in the Hawaiian language, false
 * otherwise
 */
bool IsValidCharacter(const char& c) {
  std::cout << "Input to IsValidCharacter() : \"" << c << "\"" << std::endl;

  std::vector<char> valid_characters{
      'a', 'e', 'i', 'o', 'u', 'p', 'k', 'h', 'l', 'm', 'n', 'w', ' ', '\''};
  for (unsigned int i = 0; i < valid_characters.size(); ++i) {
    if (c == valid_characters[i]) {
      return true;
    }
  }
  return false;
}

/**
 * TODO: Implement this function
 * @param word word to check validity of
 * @return true if every character in word is a valid character in the Hawaiian
 * language, false otherwise
 */
bool IsValidWord(const std::string& word) {
  std::cout << "Input to IsValidWord() : " << word << std::endl;

  std::string word_check = StringToLower(word);
  for (char c : word_check) {
    if (!IsValidCharacter(c)) {
      return false;
    }
  }
  return true;
}

/**
 * TODO: Implement this function
 * @param c consonant to get pronunciation of
 * @param prev character before c, used for determining w translation
 *    set to null character as default if no value is passed in
 * @return pronunciation of the consonant c as a char
 */
char ConsonantPronunciation(const char& c, const char& prev) {
  std::cout << "Input to ConsonantPronunciation() : \"" << c << "\" \"" << prev
            << "\"" << std::endl;
  if (!IsConsonant(c)) {
    return '\0';
  }
  std::vector<char> normal{'p', 'k', 'h', 'l', 'm', 'n'};
  for (unsigned int i = 0; i < normal.size(); i++) {
    if (normal[i] == c) {
      return normal[i];
    }
  }

  if ((prev == '\0' || prev == 'a') && c == 'w') {
    return 'w';
  }
  if (prev == 'i' || prev == 'e') {
    return 'v';
  }
  if (prev == 'u' || prev == 'o') {
    return 'w';
  }
  if (prev == ' ' && c == 'w') {
    return 'w';
  }
  return '\0';
}

std::string VowelGroupPronunciation(const char& v1, const char& v2) {
  std::cout << "Input to VowelGroupPronunciation() : \"" << v1 << "\" \"" << v2
            << "\"" << std::endl;

  if (!IsVowel(v1)) {
    return "";
  }
  if (v1 == 'a' && (v2 == 'i' || v2 == 'e')) {
    return "eye";
  }
  if (v1 == 'a' && (v2 == 'o' || v2 == 'u')) {
    return "ow";
  }
  if (v1 == 'e' && v2 == 'i') {
    return "ay";
  }
  if (v1 == 'e' && v2 == 'u') {
    return "eh-oo";
  }
  if (v1 == 'i' && v2 == 'u') {
    return "ew";
  }
  if (v1 == 'o' && v2 == 'i') {
    return "oy";
  }
  if (v1 == 'o' && v2 == 'u') {
    return "ow";
  }
  if (v1 == 'u' && v2 == 'i') {
    return "ooey";
  }
  return "";
}

std::string SingleVowelPronunciation(const char& v) {
  std::cout << "Input to SingleVowelPronunciation() : \"" << v << "\""
            << std::endl;

  if (!IsVowel(v)) {
    return "";
  }
  if (v == 'a') {
    return "ah";
  }
  if (v == 'e') {
    return "eh";
  }
  if (v == 'i') {
    return "ee";
  }
  if (v == 'o') {
    return "oh";
  }

  return "oo";
}

std::string ProcessCharacter(const char& prev,
                             const char& curr,
                             const char& next) {
  std::cout << "Input to ProcessCharacter() : \"" << prev << "\" \"" << curr
            << "\" \"" << next << "\"" << std::endl;

  std::string to_return;
  if (IsVowel(curr) ) {
    if (IsVowelGroup(curr, next)) {
      to_return = VowelGroupPronunciation(curr, next);
    } else {
      to_return =  SingleVowelPronunciation(curr);
    }
  } else if (IsConsonant(curr)) {
    to_return = ConsonantPronunciation(curr, prev);
  } else {
    to_return = std::string(1, curr);
  }
  return to_return;
}
bool CheckNext(char next) {
  return ((next != ' ') && (next != '\'') && (next != '\0'));
}

std::string Pronunciation(const std::string& word) {
  std::string word_pro;  
  char previous = '\0';
  char current = '\0';
  char next = '\0';
  size_t i = 0;
  while (i < word.length()) {
    current = word[i];
    if (i < word.length() - 1) {
      next = word[i + 1];
    } else {next = '\0';}
    std::string pronunciation;
    if (IsVowel(current)) {
      if (IsVowelGroup(current, next)) {
        pronunciation = VowelGroupPronunciation(current, next);
        i += 2;
        if (CheckNext(next)&& (i <= word.length() - 1)) {pronunciation += '-';}
      } else {
        pronunciation = SingleVowelPronunciation(current);
        i++;
        if (CheckNext(next)&& (i <= word.length() - 1)) {pronunciation += '-';}
      }
    } else if (IsConsonant(current)) {
      pronunciation = ConsonantPronunciation(current, previous);
      i++;
    } else {
      pronunciation = std::string(1, current);
      i++;
    }
    word_pro += pronunciation;
    previous = current;
  }
  return word_pro;
}

std::string GetPronunciation(const std::string& hawaiian_word) {
  if (!IsValidWord(hawaiian_word)) {
    throw std::invalid_argument("Invalid word");
  }
  std::string lower_case = StringToLower(hawaiian_word);
  return Pronunciation(lower_case);
}