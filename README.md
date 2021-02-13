# Pricer-Monte-Carlo

## Abstract

Le but de notre code est de calculer le prix d'une option et ses grecs (sensibilités du prix de l'option à ses paramètres) via Monte-Carlo. Pour cela nous utilisons tout d'abord, les formules de Black and Scholes (B&S), pour calculer le prix de nos options et des grecs comme point d'ancrage pour la vérification du Monte-Carlo et aussi pour calculer l'erreur d'estimation des simulations (l'intervalle de confiance). Nous simulons ensuite via Monte-Carlo, N simulations mouvements Browniens géométriques pour retrouver notre prix ou bien nos sensibilités delta (**∆**) et gamma (**Γ**) sous Black and Scholes en formule fermée.

Plusieurs classes ont été créées pour implémenter notre code. Concernant l'architecture (voir Excel "ArchitectureProjet.xlsx") notre code s'articule autour de trois grands axes :
- Un axe **Loi**
- Un axe **Pay-off**
- Un axe **Monte-Carlo**

## 1 Axe Loi:

Pour pouvoir simuler notre Monte-Carlo il nous faut simuler des lois et des mouvements browniens. Tout d'abord rappelons que toutes nos classes découlent d'une seule classe : la classe CProbaLaw. Nous utilisons donc ici l'héritage et le polymorphisme sur toutes les classes qui en découlent. Les classes en rapport aux simulations de la sont:
- **CProbaLaw** : Classe mère qui est une classe virtuelle pure pour donner la forme des classes filles.
- **CProbaLawWithMoment** : Classe mère/fille qui est aussi une classe virtuelle pure, cette classe nous retourne les moments d'ordre un et deux. Celle-ci hérite CProbaLaw.
- **CUniforme** : Classe fille, cette classe hérite de **CProbaLawWithMoment** et permet de simuler la loi uniforme qui nous permettra de simuler la loi normale.
- **CNormale** : Classe fille, cette classe hérite de **CProbaLawWithMoment** et permet de simuler la loi normale via la méthode de **Box-Muller**. Rapidement, sa définition mathématique est la suivante. Soient <img src="http://www.sciweavers.org/tex2img.php?eq=U_1&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=0" align="center" border="0" alt="U_1" width="24" height="18" /> et <img src="http://www.sciweavers.org/tex2img.php?eq=U_2&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=0" align="center" border="0" alt="U_2" width="24" height="18" /> deux variables aléatoires indépendantes uniformément distribuées dans ]0,1]. Soient,
- <a href="https://fr.wikipedia.org/wiki/M%C3%A9thode_de_Box-Muller" target="_blank"><img src="https://latex.codecogs.com/gif.latex?Z_0&space;=&space;R*cos(\theta&space;)&space;=&space;\sqrt{-2ln(U_1)}*cos(2\pi*U_2)" title="Z_0 = R*cos(\theta ) = \sqrt{-2ln(U_1)}*cos(2\pi*U_2)" /></a>
- <a href="https://fr.wikipedia.org/wiki/M%C3%A9thode_de_Box-Muller" target="_blank"><img src="https://latex.codecogs.com/gif.latex?Z_1&space;=&space;R*cos(\theta&space;)&space;=&space;\sqrt{-2ln(U_1)}*cos(2\pi*U_2)" title="Z_1 = R*cos(\theta ) = \sqrt{-2ln(U_1)}*cos(2\pi*U_2)" /></a>
