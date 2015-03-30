package countdown;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Scanner;

public class CopyOfCountdown {

	private static void findWord(int[] positions, String sortedWord, HashMap<String,LinkedList<String>> dictionary){
		String word = takeWord(positions, sortedWord);
		
		if(dictionary.containsKey(word)){
			System.out.println(dictionary.get(word));
		}
		
		if(positions[0]==sortedWord.length()-positions.length){
			//we're finished
		}else{
			// from max position back to start.
			// find the letter which is not at its final position 
			// and move it to +1 and all those in front of it.)
			for(int i=positions.length-1;i>=0;i--){
				
				//current position != word.len - (amount of positions - your index)
				//this gives the furthest you can be from the end. e.g. when to stop			
				if(positions[i]!=(sortedWord.length()-(positions.length-i))){
					
					//Move letter forward a place
					positions[i]++;
					int currPos = positions[i];
					int counter = 1;
					
					//The new positions
					for(int j = i+1;j<=positions.length-1;j++){
						positions[j] = currPos + counter;
						counter++;
					}
					
					findWord(positions,sortedWord,dictionary);
				} //If you reach else, you have reached the furthest part for that letter.
			}
		}
	
		return;
	}
		
	private static String takeWord(int[] positions, String sortedWord) {
		String rtnString = "";
		
		for(int i = 0;i<positions.length;i++){
			rtnString = rtnString + sortedWord.charAt(positions[i]);
		}
		return rtnString;
	}

	private static int[] initialiseArray(int num){
        int[] positions = new int[num]; 
        
        for(int i = 0;i<num;i++){
        	positions[i] = i;
        }
        return positions;
	}
	
	public static String rtnSortedInput(String input){
        char[] chars = input.toCharArray();
        Arrays.sort(chars);
        input = new String(chars);
        return input;
	}
	
	public static String getSortedInput(){
		Scanner reader = new Scanner(System.in);
		System.out.println("Enter the letters");
		String word = reader.nextLine();
		System.out.println("Your letters are: " + word);

        return rtnSortedInput(word);
	}
	
	public static HashMap<String,LinkedList<String>> rtnDictionary(){
		//Sorted word as key, list of words 
		HashMap<String,LinkedList<String>> dictionary = new HashMap<String,LinkedList<String>>();
		String file = "./textplay.txt";
		
		//Read in lines and add to dictionary
		try (BufferedReader br = new BufferedReader(new FileReader(file))) {
		    String originalLine;
		  
		    while ((originalLine = br.readLine()) != null) {
		    	String sortInput = rtnSortedInput(originalLine);
		    	
		    	//Contains key already, update with new word
		    	if(dictionary.containsKey(sortInput)){
		    		LinkedList<String> wordList = dictionary.get(sortInput);
		    		wordList.addLast(originalLine);
		    		dictionary.put(originalLine, wordList);
		    	}else{
		    		//Create key and add original
		    		LinkedList<String> wordList = new LinkedList<String>();
		    		wordList.add(originalLine);
		    		dictionary.put(sortInput, wordList);
		    	}
		    }
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		return dictionary;
	}
	
	public static void main(String[] args){
		//Get sorted letters 
		String word = getSortedInput();
		HashMap<String,LinkedList<String>> dictionary = rtnDictionary();
		
		for(int i = 4;i<=9;i++){
	        int[] positions = initialiseArray(i);

	        findWord(positions,word,dictionary);
		}
	}
}
