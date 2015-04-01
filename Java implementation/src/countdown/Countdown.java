package countdown;

public class Countdown {

	private static int[] initialiseArray(int num){
		int[] positions = new int[num]; 

		for(int i = 0;i<num;i++){
			positions[i] = i;
		}
		return positions;
	}

	public static void main(String[] args){
		Dictionary dictionary = new Dictionary();
		String word = dictionary.getSortedInput();

		for(int i = 4;i<=9;i++){
			int[] positions = initialiseArray(i);
			dictionary.findWord(positions,word);
		}
	}
}
