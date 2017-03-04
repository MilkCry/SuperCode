import java.io.BufferedReader;
import java.io.IOException; 
import java.io.InputStreamReader; /**  * Created by Milk on 2017/3/1.  */ 
	public class SystemInTest 
	{ 
		public static void main(String[] args) 
		throws IOException 
		{
			BufferedReader buffer=new BufferedReader(new InputStreamReader(System.in));
			String str=buffer.readLine(); 
			char[] inputs= str.toCharArray();
			String strRes=changeInformation(inputs);
			System.out.println(strRes);
		} 
		public static String changeInformation(char[] chars)
		{ 
			char lastChar; char currentChar;
        String result=""; 
		int count=1; 
		for(int i=1;i<chars.length;i++)
			{
            currentChar=chars[i];
            lastChar=chars[i-1]  ;
			if(currentChar==lastChar)
				{
                count++;
				}
			else{
                result=result+count+lastChar;
                count=1;
				}
			}	
        result=result+count+chars[chars.length-1]; 
		return result;
		}
}  
