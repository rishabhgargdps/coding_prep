class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int res = 0;
        for(int i=0; i<flowerbed.length; i++) {
            if(flowerbed[i] == 0) {
                if(i>0 && flowerbed[i-1] == 1) {
                    continue;
                }
                if(i<flowerbed.length-1 && flowerbed[i+1] == 1) {
                    continue;
                }
                // System.out.println(i);
                res++;
                flowerbed[i] = 1;
            }
        }
        return res >= n;
    }
}