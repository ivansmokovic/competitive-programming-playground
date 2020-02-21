package arrays;

public class OneAway {

    private static int findMismatchIndex(char[] array1, char[] array2) {
        for (int i = 0; i < Math.min(array1.length, array2.length); ++i) {
            if (array1[i] != array2[i]) return i;
        }
        return Math.min(array1.length, array2.length);
    }

    private static boolean checkSubstringEquality(char[] array1, int index1, char[] array2, int index2) {
        if (array1.length == index1 && array2.length == index2) return true;
        if (array1.length - index1 != array2.length - index2) return false;
        for (int i = 0; i < array1.length - index1; ++i) {
            if (array1[index1 + i] != array2[index2 + i]) return false;
        }
        return true;
    }

    public static void main(String[] argc) {

        var str1 = "pale".toCharArray();
        var str2 = "pale".toCharArray();

        if (Math.abs(str1.length - str2.length) > 1) {
            System.out.println("False");
            return;
        }

        if (str2.length > str1.length) {
            var tmp = str1;
            str1 = str2;
            str2 = tmp;
        }

        int missmatchIndex = findMismatchIndex(str1, str2);
        boolean match;
        if (str1.length == str2.length) {
            match = checkSubstringEquality(str1, missmatchIndex + 1, str2, missmatchIndex + 1);
        } else {
            match = checkSubstringEquality(str1, missmatchIndex + 1, str2, missmatchIndex);
        }
        if (match) {
            System.out.println("True");
        } else {
            System.out.println("False");
        }


    }

}
