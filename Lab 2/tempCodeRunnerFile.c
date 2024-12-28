int dec_to_bin_8(int i_8){
    if (i_8 <= 0){
        return 0;
    }
    else{
        return 10 * dec2bin((i_8)/2) + ((i_8)%2);
    }