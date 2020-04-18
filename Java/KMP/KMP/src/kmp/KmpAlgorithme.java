package kmp;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;
import java.util.Scanner;
public class KmpAlgorithme {
	
	
static //Fonction de traitement du fichier
	String ouvrirFichier(String fichier) throws IOException {
	    Path pathToFile = Paths.get(fichier);
	    System.out.println(pathToFile.toAbsolutePath());
		String chaine = String.join("", Files.readAllLines(pathToFile));
		return chaine;
		
	}
//Fonction de pré-traitement du texte
	void Pretraitement(String pattern,int M, int Tab[]) {
		int taille = 0;
		int i = 1;
		Tab[0] = 0;
		
		//On calcule les préfixes
		while(i < M) {
			if(pattern.charAt(i) == pattern.charAt(taille)) {
				taille++;
				Tab[i] = taille;
				i++;
			}
			else { //les lettres ne sont pas identiques
				if (taille != 0) {
					taille = Tab[taille -1];
				}
				else { //si taille == 0
					Tab[i] = taille;
					i++;
				}
			}
		}
		
	}
	void KMP(String pattern, String text) {
		int M = pattern.length();
		int N = text.length();
		//Tableau contenant le plus long prefixe/suffixe
		int Tab[] = new int[M];
		int index = 0;
		int total = 0;
		
		//Pré-traitement
		
		Pretraitement(pattern,M,Tab);
		
		int i = 0;
		while(i < N) {
			if(pattern.charAt(index) == text.charAt(i)) {
				index++;
				i++;
			}
			if(index == M) {
				System.out.println("Pattern trouvé " + "à la position " + (i - index));
				index = Tab[index -1];
				total++;
			}
			else if (i < N && pattern.charAt(index) != text.charAt(i)) {
				if (index != 0) {
					index = Tab[index - 1];
				}
				else {
					i = i + 1;
				}
			}
		}
		System.out.println("Total = " + total);
	}
	public static void main(String args[]) throws IOException {
		Scanner sc = new Scanner(System.in);
		System.out.println("Saisir nom du fichier puis pattern : ");
		String fichier = sc.nextLine();
		Scanner sc2 = new Scanner(System.in);
		String pattern = sc2.nextLine();
		final long start = System.currentTimeMillis();
		String text = ouvrirFichier(fichier);
		new KmpAlgorithme().KMP(pattern,text);
		final long end = System.currentTimeMillis();
		System.out.println("Temps d'execution (milisecondes) : " + (end - start));
	}
}
