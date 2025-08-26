/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int li= 1, ri = n; 
        while (li <= ri) {
            int mi = li + ((ri - li) / 2); 
            switch(guess(mi)) {
                case  0: return mi; 
                case  1: li = mi + 1; break;
                case -1: ri = mi - 1; break;
                default: return -1; 
            }
        }
        return 0; 

    }
};