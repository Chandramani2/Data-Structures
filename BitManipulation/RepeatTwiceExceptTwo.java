
public static boolean isBitSet(int x, int index){
    return ((1 << index) & x) > 0;
}


public static void repeatTwiceExceptTwo(int [] arr){
    int x=0, y=0;
    int xor = 0;
    for(int i = 0; i < arr.length; i++){
        xor = xor ^ arr[i];
    }
    int firstSetBitIndex = 0;
    while((xor & 1) == 0){
        xor = xor >> 1;
        firstSetBitIndex++;
    }
    for(int i = 0; i < arr.length; i++){
        if(isBitSet(arr[i], firstSetBitIndex)){
            x = x^arr[i];
        }
        else{
            y = y^arr[i];
        }
    }
    System.out.println("BitSetIndex: " + firstSetBitIndex + " X: " + x + " Y: " + y);
}

public static void main() {
    int [] arr ={1,1,2,3,3,4,5,5,6,6,7,7};
    repeatTwiceExceptTwo(arr);
}
