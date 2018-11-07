/*
* Utilitaire Créer par Bastien Roy-Mazoyer
* Convertie du C# dans le cadre Scolaire
* Mis à jours le 26/09/2017
*/

#include <vector>
#include <cctype>
#include <time.h>

/// <summary>
/// Ensemble d'outil de validateur pour diverse utilisation
/// </summary>
class Outils 
{
	// Section des méthodes privé à l'utilitaire
private:

	/***** Section de constantes *****/
	const enum Mois { Janvier, Février, Mars, Avril, Mai, Juin, Juillet, Août, Septembre, Octobre, Novembre, Décembre };
	/*^^^^ Section de constantes ^^^^*/
	
	/// <summary>
	/// Permet de formatter une liste de caractère et les mettres entre []
	/// </summary>
	/// <param name="p_caractère">Les caractères à formatter </param>
	/// <returns>Les caractères formattés</returns>
	static std::string FormatterCaractèreValidation(std::string p_caractère) {
		std::string caractèreformatter = "";
		for (size_t i = 0; i < p_caractère.length(); i++)
		{
			caractèreformatter += '[';
			caractèreformatter += p_caractère[i];
			caractèreformatter += ']';
			caractèreformatter += ' ';
		}
		return caractèreformatter;
	};

	/// <summary>
	/// Permet d'extraire une liste de caractères d'un menu (les caractères entre [])
	/// </summary>
	/// <param name="p_menu">Le tableau de caractères contenant le menu </param>
	/// <returns>Les caractères du menu entre []</returns>
	static std::string AnalyserMenu(std::string p_menu) {
		std::string caractèreformatter = "";
		bool enAnalyse = false;

		for (size_t i = 0; i < p_menu.length(); i++)
		{
			if (p_menu[i] == '['&& p_menu[i + 2] == ']')
				caractèreformatter += p_menu[i + 1];
		}
		return caractèreformatter;
	};

	//Section Public des fonctions de l'utilitaire : 
public:

	/// <summary>
	/// Permet de vider la mémoiré Tampon du std::cin
	/// </summary>
	static void ViderTamponCin() {
		std::fseek(stdin, 0, SEEK_END);
		std::cin.clear();
	}

	/****************************************************************************************************************/
	/**************************************  Section de validateurs Int32  ******************************************/
	/****************************************************************************************************************/
	/// <summary>
	/// Permet de valider un Entier
	/// </summary>
	/// <param name="p_question">La question a poser à l'utilisateur </param>
	/// <returns>La valeur validée</returns>
	static int LireInt32(const std::string& p_question) {
		int nombre;

		for (;;) /*Vérifier si l'utilisateur ne rentre qu'un nombre et non un caractère*/
		{
			ViderTamponCin();

			std::cout << p_question;

			if (std::cin >> nombre)
				break;
			else
				std::cout << "S.V.P, entrez un nombre valide " << std::endl;
		}

		return nombre;
	};

	/// <summary>
	/// Permet de valider un nombre entier positif
	/// </summary>
	/// <param name="p_question">La question a poser à l'utilisateur </param>
	/// <returns>La valeur validée</returns>
	static int LireInt32Positif(const std::string& p_question) {
		int nombre;

		for (;;) /*Vérifier si l'utilisateur ne rentre qu'un nombre et non un caractère*/
		{
			ViderTamponCin();

			std::cout << p_question;
			if (std::cin >> nombre && nombre >= 0)
				break;
			else
				std::cout << "S.V.P, entrez un nombre valide " << std::endl;
		}

		return nombre;
	};

	/// <summary>
	/// Permet de valider un nombre entier avec un minimum
	/// </summary>
	/// <param name="p_question">La question a poser à l'utilisateur </param>
	/// <param name="p_minimum">La valeur minimale que l'entier peut prendre </param>
	/// <returns>La valeur validée</returns>
	static int LireInt32AvecMinimum(const std::string& p_question, int p_minimum) {
		int nombre;

		for (;;) /*Vérifier si l'utilisateur ne rentre qu'un nombre et non un caractère*/
		{
			ViderTamponCin();

			std::cout << p_question;
			if (std::cin >> nombre && nombre >= p_minimum)
				break;
			else
				std::cout << "S.V.P, entrez un nombre valide (min =" << p_minimum << ")" << std::endl;
		}

		return nombre;
	};

	/// <summary>
	/// Permet de valider un nombre entier dans un interval
	/// </summary>
	/// <param name="p_question">La question a poser à l'utilisateur </param>
	/// <param name="p_minimum">La valeur minimale que l'entier peut prendre </param>
	/// <param name="p_maximum">La valeur maximale que l'entier peut prendre </param>
	/// <returns>La valeur validée</returns>
	static int LireInt32DansIntervalle(const std::string& p_question, int p_minimum, int p_maximum) {
		int nombre;

		for (;;) /*Vérifier si l'utilisateur ne rentre qu'un nombre et non un caractère*/
		{
			ViderTamponCin();

			std::cout << p_question;
			if (std::cin >> nombre && (p_minimum <= nombre && nombre <= p_maximum))
				break;
			else
				std::cout << "S.V.P, entrez un nombre valide (" << p_minimum << "-" << p_maximum << ")" << std::endl;
		}

		return nombre;
	};

	/// <summary>
	/// Permet de valider un nombre entier avec un minimum avec une sentinelle
	/// </summary>
	/// <param name="p_question">La question a poser à l'utilisateur </param>
	/// <param name="p_minimum">La valeur minimale que l'entier peut prendre </param>
	/// <param name="p_sentinelle">La valeur de la sentinelle pour un arrêt</param>
	/// <returns>La valeur validée</returns>
	static int LireInt32AvecMinimumOuSentinelle(const std::string& p_question, int p_minimum, int p_sentinelle) {
		int nombre;

		for (;;) /*Vérifier si l'utilisateur ne rentre qu'un nombre et non un caractère*/
		{
			ViderTamponCin();

			std::cout << p_question;
			if (std::cin >> nombre && (p_minimum <= nombre || nombre == p_sentinelle))
				break;
			else

				std::cout << "S.V.P, entrez un nombre valide (min =" << p_minimum << ", " << p_sentinelle << " pour quitter)" << std::endl;
		}

		return nombre;
	};

	/// <summary>
	/// Permet de valider un nombre entier dans un interval avec une sentinelle
	/// </summary>
	/// <param name="p_question">La question a poser à l'utilisateur </param>
	/// <param name="p_minimum">La valeur minimale que l'entier peut prendre </param>
	/// <param name="p_maximum">La valeur maximale que l'entier peut prendre </param>
	/// <param name="p_sentinelle">La valeur de la sentinelle pour un arrêt</param>
	/// <returns>La valeur validée</returns>
	static int LireInt32DansIntervalleOuSentinelle(const std::string& p_question, int p_minimum, int p_maximum, int p_sentinelle) {
		int nombre;

		for (;;) /*Vérifier si l'utilisateur ne rentre qu'un nombre et non un caractère*/
		{
			ViderTamponCin();

			std::cout << p_question;

			if (std::cin >> nombre && ((p_minimum <= nombre && nombre <= p_maximum) || nombre == p_sentinelle))
				break;
			else
				std::cout << "S.V.P, entrez un nombre valide (" << p_minimum << "-" <<
				p_maximum << ", " << p_sentinelle << " pour quitter)" << std::endl;
		}

		return nombre;
	};

	/****************************************************************************************************************/
	/**************************************  Section de validateurs Double  *****************************************/
	/****************************************************************************************************************/
	/// <summary>
	/// Permet de valider un nombre à virgule ( un double)
	/// </summary>
	/// <param name="p_question">La question a poser à l'utilisateur </param>
	/// <returns>La valeur validée</returns>
	static double LireDouble(const std::string& p_question) {
		double nombre;

		for (;;) /*Vérifier si l'utilisateur ne rentre qu'un nombre et non un caractère*/
		{
			ViderTamponCin();

			std::cout << p_question;
			if (std::cin >> nombre)
				break;
			else
				std::cout << "S.V.P, entrez un nombre valide " << std::endl;
		}

		return nombre;
	};

	/// <summary>
	/// Permet de valider un nombre positif
	/// </summary>
	/// <param name="p_question">La question a poser à l'utilisateur </param>
	/// <returns>La valeur validée</returns>
	static double LireDoublePositif(const std::string& p_question) {
		double nombre;

		for (;;) /*Vérifier si l'utilisateur ne rentre qu'un nombre et non un caractère*/
		{
			ViderTamponCin();

			std::cout << p_question;
			if (std::cin >> nombre && nombre >= 0)
				break;
			else
				std::cout << "S.V.P, entrez un nombre valide " << std::endl;
		}

		return nombre;
	};

	/// <summary>
	/// Permet de valider un nombre avec un minimum
	/// </summary>
	/// <param name="p_question">La question a poser à l'utilisateur </param>
	/// <param name="p_minimum">La valeur minimale que le nombre peut prendre </param>
	/// <returns>La valeur validée</returns>
	static double LireDoubleAvecMinimum(const std::string& p_question, double p_minimum) {
		double nombre;

		for (;;) /*Vérifier si l'utilisateur ne rentre qu'un nombre et non un caractère*/
		{
			ViderTamponCin();

			std::cout << p_question;

			if (std::cin >> nombre && nombre >= p_minimum)
				break;
			else
				std::cout << "S.V.P, entrez un nombre valide (min =" << p_minimum << ")" << std::endl;
		}

		return nombre;
	};

	/// <summary>
	/// Permet de valider un nombre dans un interval
	/// </summary>
	/// <param name="p_question">La question a poser à l'utilisateur </param>
	/// <param name="p_minimum">La valeur minimale que le nombre peut prendre </param>
	/// <param name="p_maximum">La valeur maximale que le nombre peut prendre </param>
	/// <returns>La valeur validée</returns>
	static double LireDoubleDansIntervalle(const std::string& p_question, double p_minimum, double p_maximum) {
		double nombre;

		for (;;) /*Vérifier si l'utilisateur ne rentre qu'un nombre et non un caractère*/
		{
			ViderTamponCin();

			std::cout << p_question;
			if (std::cin >> nombre && (p_minimum <= nombre && nombre <= p_maximum))
				break;
			else
				std::cout << "S.V.P, entrez un nombre valide (" << p_minimum << "-" << p_maximum << ")" << std::endl;
		}

		return nombre;
	};

	/// <summary>
	/// Permet de valider un nombre avec un minimum avec une sentinelle
	/// </summary>
	/// <param name="p_question">La question a poser à l'utilisateur </param>
	/// <param name="p_minimum">La valeur minimale que le nombre peut prendre </param>
	/// <param name="p_sentinelle">La valeur de la sentinelle pour un arrêt</param>
	/// <returns>La valeur validée</returns>
	static double LireDoubleAvecMinimumOuSentinelle(const std::string& p_question, double p_minimum, double p_sentinelle) {
		double nombre;

		for (;;) /*Vérifier si l'utilisateur ne rentre qu'un nombre et non un caractère*/
		{
			ViderTamponCin();

			std::cout << p_question;
			if (std::cin >> nombre && (p_minimum <= nombre || nombre == p_sentinelle))
				break;
			else
				std::cout << "S.V.P, entrez un nombre valide (min =" << p_minimum << ", " << p_sentinelle << " pour quitter)" << std::endl;
		}

		return nombre;
	};

	/// <summary>
	/// Permet de valider un nombre dans un interval avec une sentinelle
	/// </summary>
	/// <param name="p_question">La question a poser à l'utilisateur </param>
	/// <param name="p_minimum">La valeur minimale que le nombre peut prendre </param>
	/// <param name="p_maximum">La valeur maximale que le nombre peut prendre </param>
	/// <param name="p_sentinelle">La valeur de la sentinelle pour un arrêt</param>
	/// <returns>La valeur validée</returns>
	static double LireDoubleDansIntervalleOuSentinelle(const std::string& p_question, double p_minimum, double p_maximum, double p_sentinelle) {
		double nombre;

		for (;;) /*Vérifier si l'utilisateur ne rentre qu'un nombre et non un caractère*/
		{
			ViderTamponCin();

			std::cout << p_question;
			if (std::cin >> nombre && ((p_minimum <= nombre && nombre <= p_maximum) || nombre == p_sentinelle))
				break;
			else
				std::cout << "S.V.P, entrez un nombre valide (" << p_minimum << "-" << p_maximum << ", " << p_sentinelle << " pour quitter)" << std::endl;
		}

		return nombre;
	};
	
	/****************************************************************************************************************/
	/**************************************  Section de validateurs Float  *****************************************/
	/****************************************************************************************************************/
	/// <summary>
	/// Permet de valider un nombre à virgule ( un double)
	/// </summary>
	/// <param name="p_question">La question a poser à l'utilisateur </param>
	/// <returns>La valeur validée</returns>
	static float LireFloat(const std::string& p_question) {
		float nombre;

		for (;;) /*Vérifier si l'utilisateur ne rentre qu'un nombre et non un caractère*/
		{
			ViderTamponCin();

			std::cout << p_question;
			if (std::cin >> nombre)
				break;
			else
				std::cout << "S.V.P, entrez un nombre valide " << std::endl;
		}

		return nombre;
	};

	/// <summary>
	/// Permet de valider un nombre positif
	/// </summary>
	/// <param name="p_question">La question a poser à l'utilisateur </param>
	/// <returns>La valeur validée</returns>
	static float LireFloatPositif(const std::string& p_question) {
		float nombre;

		for (;;) /*Vérifier si l'utilisateur ne rentre qu'un nombre et non un caractère*/
		{
			ViderTamponCin();

			std::cout << p_question;
			if (std::cin >> nombre && nombre >= 0)
				break;
			else
				std::cout << "S.V.P, entrez un nombre valide " << std::endl;
		}

		return nombre;
	};

	/// <summary>
	/// Permet de valider un nombre avec un minimum
	/// </summary>
	/// <param name="p_question">La question a poser à l'utilisateur </param>
	/// <param name="p_minimum">La valeur minimale que le nombre peut prendre </param>
	/// <returns>La valeur validée</returns>
	static float LireFloatAvecMinimum(const std::string& p_question, float p_minimum) {
		float nombre;

		for (;;) /*Vérifier si l'utilisateur ne rentre qu'un nombre et non un caractère*/
		{
			ViderTamponCin();

			std::cout << p_question;

			if (std::cin >> nombre && nombre >= p_minimum)
				break;
			else
				std::cout << "S.V.P, entrez un nombre valide (min =" << p_minimum << ")" << std::endl;
		}

		return nombre;
	};

	/// <summary>
	/// Permet de valider un nombre dans un interval
	/// </summary>
	/// <param name="p_question">La question a poser à l'utilisateur </param>
	/// <param name="p_minimum">La valeur minimale que le nombre peut prendre </param>
	/// <param name="p_maximum">La valeur maximale que le nombre peut prendre </param>
	/// <returns>La valeur validée</returns>
	static float LireFloatDansIntervalle(const std::string& p_question, float p_minimum, float p_maximum) {
		float nombre;

		for (;;) /*Vérifier si l'utilisateur ne rentre qu'un nombre et non un caractère*/
		{
			ViderTamponCin();

			std::cout << p_question;
			if (std::cin >> nombre && (p_minimum <= nombre && nombre <= p_maximum))
				break;
			else
				std::cout << "S.V.P, entrez un nombre valide (" << p_minimum << "-" << p_maximum << ")" << std::endl;
		}

		return nombre;
	};

	/// <summary>
	/// Permet de valider un nombre avec un minimum avec une sentinelle
	/// </summary>
	/// <param name="p_question">La question a poser à l'utilisateur </param>
	/// <param name="p_minimum">La valeur minimale que le nombre peut prendre </param>
	/// <param name="p_sentinelle">La valeur de la sentinelle pour un arrêt</param>
	/// <returns>La valeur validée</returns>
	static float LireFloatAvecMinimumOuSentinelle(const std::string& p_question, float p_minimum, float p_sentinelle) {
		float nombre;

		for (;;) /*Vérifier si l'utilisateur ne rentre qu'un nombre et non un caractère*/
		{
			ViderTamponCin();

			std::cout << p_question;
			if (std::cin >> nombre && (p_minimum <= nombre || nombre == p_sentinelle))
				break;
			else
				std::cout << "S.V.P, entrez un nombre valide (min =" << p_minimum << ", " << p_sentinelle << " pour quitter)" << std::endl;
		}

		return nombre;
	};

	/// <summary>
	/// Permet de valider un nombre dans un interval avec une sentinelle
	/// </summary>
	/// <param name="p_question">La question a poser à l'utilisateur </param>
	/// <param name="p_minimum">La valeur minimale que le nombre peut prendre </param>
	/// <param name="p_maximum">La valeur maximale que le nombre peut prendre </param>
	/// <param name="p_sentinelle">La valeur de la sentinelle pour un arrêt</param>
	/// <returns>La valeur validée</returns>
	static float LireFloatDansIntervalleOuSentinelle(const std::string& p_question, float p_minimum, float p_maximum, float p_sentinelle) {
		float nombre;

		for (;;) /*Vérifier si l'utilisateur ne rentre qu'un nombre et non un caractère*/
		{
			ViderTamponCin();

			std::cout << p_question;
			if (std::cin >> nombre && ((p_minimum <= nombre && nombre <= p_maximum) || nombre == p_sentinelle))
				break;
			else
				std::cout << "S.V.P, entrez un nombre valide (" << p_minimum << "-" << p_maximum << ", " << p_sentinelle << " pour quitter)" << std::endl;
		}

		return nombre;
	};

	/****************************************************************************************************************/
	/**************************************  Section de validateurs String  *****************************************/
	/****************************************************************************************************************/
	/// <summary>
	/// Permet de Lire un string
	/// </summary>
	/// <param name="p_question">La question a poser à l'utilisateur</param>
	/// <returns>Le string sans les espaces des extrémités</returns>
	static std::string LireString(const std::string& p_question) {
		std::string string;

		for (;;) /*Vérifier si l'utilisateur ne rentre que des caractères*/
		{
			ViderTamponCin();

			std::cout << p_question;

			if (std::getline(std::cin, string))
				break;
			else
				std::cout << "Erreur Critique" << std::endl;
		}

		return string;
	};

	/// <summary>
	/// Permet de contrôler la taille d'un texte (string)
	/// </summary>
	/// <param name="p_question">La question a poser à l'utilisateur</param>
	/// <param name="p_lgMin">Longueur minimale du texte</param>
	/// <param name="p_lgMax">Longueur maximal du texte</param>
	/// <returns>Le texte sans les espaces des extrémités</returns>
	static std::string LireStringTailleContrôlée(const std::string& p_question, int p_lgMin, int p_lgMax) {
		std::string string;

		for (;;) /*Vérifier si l'utilisateur ne rentre que des caractères*/
		{
			ViderTamponCin();

			std::cout << p_question;

			int stringLength = string.length();
			if (std::getline(std::cin, string) && (p_lgMin <= stringLength && stringLength <= p_lgMax))
				break;
			else
			{
				std::cout << "S.V.P, la réponse doit être entre " << p_lgMin << " et " << p_lgMax
					<< " caractères" << std::endl;
			}
		}

		return string;
	};

	/// <summary>
	/// Permet de valider si le texte est non-vide
	/// </summary>
	/// <param name="p_question">La question à poser à l'utilisateur</param>
	/// <returns>La String que l'utilisateur à écrit</returns>
	static std::string LireStringNonVide(const std::string& p_question) {
		std::string string;

		for (;;) /*Vérifier si l'utilisateur ne rentre que des caractères*/
		{
			ViderTamponCin();

			std::cout << p_question;

			if (std::getline(std::cin, string) && string.length() > 0)
				break;
			else
				std::cout << "S.V.P, la réponse ne peut pas être vide " << std::endl;

		}

		return string;
	};

	/// <summary>
	/// Permet de valider si le texte est non-vide et n'est qu'un seul mot
	/// </summary>
	/// <param name="p_question">La question à poser à l'utilisateur</param>
	/// <returns>le mot que l'utilisateur à écrit</returns>
	static std::string LireMotNonVide(const std::string& p_question) {
		std::string string;

		for (;;) /*Vérifier si l'utilisateur ne rentre que des caractères*/
		{
			ViderTamponCin();

			std::cout << p_question;

			if (std::getline(std::cin, string) && (string.find_first_of(' ') == std::string::npos))
				break;
			else
				std::cout << "S.V.P, la réponse ne peut pas être vide et doit être un seul mot " << std::endl;

		}

		return string;
	};
	/****************************************************************************************************************/
	/**************************************  Section de validateurs Char  *******************************************/
	/****************************************************************************************************************/
	/// <summary>
	/// Permet de lire un Caractère
	/// </summary>
	/// <param name="p_question">La question a poser à l'utilisateur</param>
	/// <returns>Le caractère validé</returns>
	static char LireChar(const std::string& p_question) {

		ViderTamponCin();

		std::cout << p_question;

		return std::getchar();
	};

	/// <summary>
	/// Permet de lire un Caractère
	/// </summary>
	/// <param name="p_question">La question a poser à l'utilisateur</param>
	/// <param name="p_caractèresVérifier">La suite de caractère à vérifier sous une forme de string</param>
	/// <returns>Le caractère validé</returns>
	static char LireCharAvecVérification(const std::string& p_question, const std::string& p_caractèresVérifier) {
		char caractère;

		for (;;) /*Vérifier si l'utilisateur ne rentre que certains caractères*/
		{
			ViderTamponCin();

			std::cout << p_question;
			caractère = std::getchar();
			if (p_caractèresVérifier.find_first_of(std::toupper(caractère)) != std::string::npos)
				break;
			else
			{
				std::cout << "S.V.P, Veuillez entrer un des caractères suivant " <<
					FormatterCaractèreValidation(p_caractèresVérifier) << std::endl;
			}
		}

		return caractère;
	};

	/// <summary>
	/// Permet de lire un Caractère dans un menu
	/// </summary>
	/// <param name="p_menu">Le menu à suggérer à l'utilisateur, les lettres à choisirs doivent être entre crochet [ ] 
	/// Exemple : "[A]vion\n[B]ateau\n[C]amion\nVotre Choix : "</param>
	/// <returns>Le caractère validé</returns>
	static char LireMenu(const std::string& p_menu) {
		char caractère;
		std::string listeCaractères = AnalyserMenu(p_menu);
		for (;;) /*Vérifier si l'utilisateur ne rentre que certains caractères*/
		{
			ViderTamponCin();

			std::cout << p_menu;

			caractère = std::getchar();
			if (listeCaractères.find_first_of(std::toupper(caractère)) != std::string::npos)
				break;
			else
			{
				std::cout << std::endl << "S.V.P, Veuillez entrer un des caractères suivant " <<
					FormatterCaractèreValidation(listeCaractères) << std::endl;
			}
		}

		return caractère;
	};

	/****************************************************************************************************************/
	/**************************************  Section de validateurs Bool  *******************************************/
	/****************************************************************************************************************/
	/// <summary>
	/// Permet de valider par oui ou par non un choix
	/// </summary>
	/// <param name="p_question">La question a poser à l'utilisateur</param>
	/// <returns>Vrai si Oui, Faux si Non.</returns>
	static bool ConfirmerOuiNon(const std::string& p_question) {
		char caractère;

		for (;;) /*Vérifier si l'utilisateur ne rentre que certains caractères*/
		{
			ViderTamponCin();

			std::cout << p_question;

			caractère = std::getchar();
			if (std::tolower(caractère) == 'o' || std::tolower(caractère) == 'n')
				break;
			else
				std::cout << "S.V.P, Veuillez entrer un des caractères suivant " << FormatterCaractèreValidation("ON") << std::endl;
		}

		return (std::tolower(caractère) == 'o') ? true : false;
	};

	/****************************************************************************************************************/
	/************************************  Section de validateurs List<>  *******************************************/
	/****************************************************************************************************************/
	/// <summary>
	/// Permet de créer une séquence de nombres entiers
	/// </summary>
	/// <param name="p_départ">Nombre de la valeur de départ</param>
	/// <param name="p_nbDeValeurs">Combien de valeurs dans la liste</param>
	/// <returns>La liste de la séquence des entiers</returns>
	static std::vector<int> SéquenceNumérique(int p_départ, int p_nbDeValeurs) {
		std::vector<int> séquenceNumérique(p_nbDeValeurs);

		for (size_t i = 0; i != p_nbDeValeurs; i++)
		{
			séquenceNumérique.at(i) = p_départ + i;
		}

		return séquenceNumérique;
	};

	/****************************************************************************************************************/
	/***********************************  Section de Générateur Aléatoire *******************************************/
	/****************************************************************************************************************/

	/// <summary>
	/// Génére un nombre entier aléatoire dans un intervalle
	/// </summary>
	/// <param name="min">Nombre minimum inclus dans la liste</param>
	/// <param name="max">Nombre maximum exclus de la liste</param>
	/// <returns>Le nombre générer aléatoirement</returns>
	static int NombreAléatoireEntier(int p_min, int p_max) {
		std::srand((int) time(NULL));

		return rand() % (p_max - p_min) + p_min;
	};

	/****************************************************************************************************************/
	/***********************************    Section de Gestion de Date   ********************************************/
	/****************************************************************************************************************/
	/// <summary>
	/// Permet de lire une date quelconque avec vérification du mois et du jour
	/// </summary>
	/// <param name="p_question">La question à poser à l'utilisateur pour savoir une date</param>
	/// <returns>La date validé pour le mois et le jour</returns>
	static tm LireDate(std::string p_question)
	{
		ViderTamponCin();

		int jours[12] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int joursBi[12] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		time_t dateVide;
		tm date = { 0 };
		localtime_s(&date, &dateVide);
		std::cout << p_question;
		int année = LireInt32("\nAnnées ? ");;

		for (size_t i = 0; i < 12; i++)
		{
			std::cout << i + 1 << "- " << MoisEnString(i) << "\n";
		}

		std::string messageMois = "\nMois de l'année ";
		messageMois += std::to_string(année);
		messageMois += " ? ";

		int mois = LireInt32DansIntervalle(messageMois, 1, 12);;

		int jour;

		std::string messageJour = "\nLe jour du mois de ";
		messageJour += MoisEnString(mois - 1);
		messageJour += " ? ";

		jour = ((année % 4 == 0 && année % 100 != 0) || année % 400 == 0) ?
			LireInt32DansIntervalle(messageJour, 1, joursBi[mois - 1]) :
			LireInt32DansIntervalle(messageJour, 1, jours[mois - 1]);

		date.tm_sec = date.tm_min = date.tm_hour = 0;
		date.tm_year = année - 1900;
		date.tm_mon = mois - 1;
		date.tm_mday = jour;
		date.tm_isdst = -1;


		return date;
	}

	/// <summary>
	/// Transforme la valeur du mois de tm en type Enum Mois
	/// </summary>
	/// <param name="p_mois">Valeur numérique du mois à formatter selon tm_mon</param>
	/// <returns>Le mois correspondant en Enum</returns>
	static Mois AttribuerEnumMois(int p_mois) {
		switch (p_mois)
		{
		case 0:return Mois::Janvier;
		case 1:return Mois::Février;
		case 2:return Mois::Mars;
		case 3:return Mois::Avril;
		case 4:return Mois::Mai;
		case 5:return Mois::Juin;
		case 6:return Mois::Juillet;
		case 7:return Mois::Août;
		case 8:return Mois::Septembre;
		case 9:return Mois::Octobre;
		case 10:return Mois::Novembre;
		default:
			return Mois::Décembre;
		}
	}

	/// <summary>
	/// Formatte la valeur du mois de tm en string
	/// </summary>
	/// <param name="p_mois">Valeur numérique du mois à formatter selon tm_mon</param>
	/// <returns>Le mois en string</returns>
	static std::string MoisEnString(int p_mois) {
		switch (p_mois)
		{
		case 0:return "Janvier";
		case 1:return "Février";
		case 2:return "Mars";
		case 3:return "Avril";
		case 4:return "Mai";
		case 5:return "Juin";
		case 6:return "Juillet";
		case 7:return "Août";
		case 8:return "Septembre";
		case 9:return "Octobre";
		case 10:return "Novembre";
		default:
			return "Décembre";
		}
	}
};
