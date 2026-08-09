class Base64Encoder {

    static final String BASE64 =
            "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    static String encode(String input) {

        StringBuilder bits = new StringBuilder();

        for (char c : input.toCharArray()) {
            String binary = Integer.toBinaryString(c);

            while (binary.length() < 8) {
                binary = "0" + binary;
            }

            bits.append(binary);
        }

        StringBuilder result = new StringBuilder();

        for (int i = 0; i < bits.length(); i += 6) {

            String chunk = bits.substring(i, Math.min(i + 6, bits.length()));

            while (chunk.length() < 6) {
                chunk += "0";
            }

            int value = Integer.parseInt(chunk, 2);

            result.append(BASE64.charAt(value));
        }

        int remainder = input.length() % 3;

        if (remainder == 1) {
            result.append("==");
        } else if (remainder == 2) {
            result.append("=");
        }

        return result.toString();
    }

    public static void main(String[] args) {

        System.out.println(encode("Man"));
        System.out.println(encode("Ma"));
        System.out.println(encode("A"));
        System.out.println(encode("Cat"));
        System.out.println(encode("Hello World"));
    }
}
