import java.security.MessageDigest;
import java.util.Arrays;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import javax.crypto.spec.SecretKeySpec;
import javax.crypto.spec.IvParameterSpec;
 
import javax.crypto.Cipher;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;
 
public class prex2 {
  static byte[] IV;
  
  public static void main(String [] args) {
    try {
 
	String IVHex =  "770b80259ec33beb2561358a9f2dc617";
	String keyHex = "36f18357be4dbd77f050515c73fcf9f2";
	String cipherHex = "e46218c0a53cbeca695ae45faa8952aa0e311bde9d4e01726d3184c34451";
	
	// convert IV hex to ASCII
	IV = hexStringToByteArray(IVHex);
	
      byte[] cipher = hexStringToByteArray(cipherHex);
 
      String decrypted = decrypt(cipher, hexStringToByteArray(keyHex));
 
      System.out.println(decrypted);
 
    } catch (Exception e) {
      e.printStackTrace();
    } 
  }
 
	public static byte[] hexStringToByteArray(String s) 
	{
    	int len = s.length();
    	byte[] data = new byte[len / 2];
    	for (int i = 0; i < len; i += 2) {
        	data[i / 2] = (byte) ((Character.digit(s.charAt(i), 16) << 4) + Character.digit(s.charAt(i+1), 16));
    	}
    	return data;
	}

  	public static String decrypt(byte[] cipherText, byte[] encryptionKey) throws Exception
	{
    	Cipher cipher = Cipher.getInstance("AES/CTR/pkcs5padding", "SunJCE");
    	SecretKeySpec key = new SecretKeySpec(encryptionKey, "AES");
    	cipher.init(Cipher.DECRYPT_MODE, key,new IvParameterSpec(IV));
    	return new String(cipher.doFinal(cipherText),"UTF-8");
  	}
}