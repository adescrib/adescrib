#include "isogram.h"
#include <stdint.h>

bool is_isogram(const char phrase[])
{
   if (!phrase)
      return false;

   uint32_t letter_flags = 0;
   char sub = 'a';

   while (*phrase) {
      char letter = *phrase;
      if (letter >= 'a' && letter <= 'z')
         sub = 'a';
      else if (letter >= 'A' && letter <= 'Z')
         sub = 'A';
      else
         sub = 'X';

      if (sub != 'X') {
         if ((letter_flags & (1 << (letter - sub))) != 0)
            return false;
         else
            letter_flags |= (1 << (letter - sub));
      }
      phrase++;
   }
   return true;
}
