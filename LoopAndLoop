public class LoopAndLoop {
    public static void main(String args[]) {
        System.out.println("start");
        for (int i = 0; i < 0x7fffffff; i++) {
            if(i % 0x1000000 == 0){
                System.out.println("Now i is " + i);
            }
            if (check(i, 99) == 1835996258) {
                System.out.println("Succeed, the value is " + i);
                System.exit(0);
            }
        }
    }

    public static int check(int paramInt1, int paramInt2) {
        return chec(paramInt1, paramInt2);
    }

    public static int chec(int paramInt1, int paramInt2) {
        int result = 0;
        if (paramInt2 - 1 <= 0) {
            return paramInt1;
        } else {
            int temp = paramInt2 - 1;
            switch (paramInt2 * 2 % 3) {
                case 0:
                    result = check1(paramInt1, temp);
                    break;
                case 1:
                    result = check2(paramInt1, temp);
                    break;
                case 2:
                    result = check3(paramInt1, temp);
                    break;

                default:
                    System.err.println("Error");
                    break;
            }
        }
        return result;
    }

    public static int check1(int paramInt1, int paramInt2) {
        int j = 1;
        int i = paramInt1;
        paramInt1 = j;
        while (paramInt1 < 100) {
            i += paramInt1;
            paramInt1 += 1;
        }
        return chec(i, paramInt2);
    }

    public static int check2(int paramInt1, int paramInt2) {
        // 这里有问题，所以进行了更改，可能是jd-gui的问题
        int j = 1;
        int i = paramInt1;
        if (paramInt2 % 2 == 0) {
            j = 1;
            i = paramInt1;
            paramInt1 = j;
            while (paramInt1 < 1000) {
                i += paramInt1;
                paramInt1 += 1;
            }
            return chec(i, paramInt2);
        }
        j = 1;
        i = paramInt1;
        paramInt1 = j;
        while (paramInt1 < 1000) {
            i -= paramInt1;
            paramInt1 += 1;
        }
        return chec(i, paramInt2);
    }

    public static int check3(int paramInt1, int paramInt2) {
        int j = 1;
        int i = paramInt1;
        paramInt1 = j;
        while (paramInt1 < 10000) {
            i += paramInt1;
            paramInt1 += 1;
        }
        return chec(i, paramInt2);
    }
}
