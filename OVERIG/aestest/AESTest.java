class Untitled 
{
	public static void main(String[] args) 
	{
		String base64Text="";
		String plainText="";
		try {
		    String key = "MyEncryptionKey";
		    byte[] keyBytes = key.getBytes("UTF-8");
		    byte[] ivBytes = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
		    byte[] cipherData;
		
		    cipherData = AES256Cipher.decrypt(ivBytes, keyBytes, Base64.decode(base64Text.getBytes("UTF-8"), Base64.DEFAULT));
		    plainText = new String(cipherData, "UTF-8");            
		}
		catch ( Exception e )
		{
		    e.printStackTrace();
		}
	}
}