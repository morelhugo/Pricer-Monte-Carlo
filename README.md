# Pricer-Monte-Carlo

## Abstract

Le but de notre code est de calculer le prix d'une option et ses greeks (sensibilités du prix de l'option à ses paramètres) via Monte-Carlo. Pour cela nous utilisons tout d'abord, les formules de Black et Scholes (B&S) pour calculer le prix et les greeks de nos options comme point d'ancrage et pour évaluer l'erreur de nos simulations (intervalle de confiance). Nous simulons ensuite, via Monte-Carlo, N trajectoires de Mouvements Browniens Géométriques pour estimer le prix, le delta (**∆**) et le gamma (**Γ**) sous la mesure Black-Scholes.

L'architecture (voir `ArchitectureProjet.xlsx`) s'articule autour de trois axes :
- Un axe **Loi**
- Un axe **Pay-off**
- Un axe **Monte-Carlo**

## 1) Axe Loi

Toutes nos lois découlent d'une seule classe abstraite : **CProbaLaw**, permettant le polymorphisme pour les simulateurs.

Les classes de lois et de processus sont :
- **CProbaLaw** : classe abstraite mère pour la simulation.
- **CProbaLawWithMoment** : ajoute la génération des moments 1 et 2. Hérite de **CProbaLaw**.
- **CUniform** : simule la loi uniforme. Hérite de **CProbaLawWithMoment**.
- **CNormal** : simule la loi normale via la méthode de Box–Muller. Hérite de **CProbaLawWithMoment**.
- **CProcess** : base pour les processus stochastiques, hérite de **CProbaLaw**.
- **CBrownian** : incrément de mouvement brownien, hérite de **CProcess**.
- **CGeometricBrownian** : simule le modèle de Black–Scholes (processus géométrique), hérite de **CProcess**.

## 2) Axe Pay-off

Après simulation du processus, nous calculons les pay-offs :
- **CPayOff** : classe abstraite déclarant les interfaces `evaluation`, `price`, `delta`, `gamma` et les fonctions utilitaires `d1`, `d2`.
- **CCall** : implémente le pay-off et les formules B&S d'un Call.
- **CPut** : implémente le pay-off et les formules B&S d'un Put.
- **CDiscountFactor** : calcule le facteur d'actualisation `exp(-r T)`.
- **CVanillaOptionBS** : classe `CProbaLaw` qui encapsule un pointeur sur `CPayOff` et simule le pay-off via le mouvement géométrique. Fournit également les méthodes B&S `price()`, `delta()` et `gamma()` en formule fermée.

> _Note : on peut facilement ajouter d'autres pay-offs (butterfly, straddle, barrières) en héritant de `CPayOff`._

## 3) Axe Monte-Carlo

### 3.1) Principes fondamentaux

Dans le modèle Black–Scholes, le prix d'un Call est

<p align="center"> 
<img src="https://latex.codecogs.com/gif.latex?P=e^{-rT}\mathbb{E}^\mathbb{Q}[(S_T-K)^+]=e^{-rT}E[(S_0e^{\sigma W_T+(r-\frac{\sigma^2}{2})T}-K)^+]"/>
</p>

Par la loi des grands nombres,

<p align="center"> 
<img src="https://latex.codecogs.com/gif.latex?\hat{P}_N=\frac{1}{N}\sum_{i=1}^N P^{(i)},\quad P^{(i)}=e^{-rT}(S_0e^{\sigma\sqrt{T}N^{(i)}+(r-\frac{\sigma^2}{2})T}-K)^+"/>
</p>

### 3.2) Implémentation en C++

- **CMonteCarloMethod** : calcule le `monteCarlo(...)` renvoyant l'espérance empirique, l'erreur (IC à 95%), et les greeks empiriques (delta, gamma). Propose aussi `getEmpiricalMean`, `getEmpiricalVariance`, `error`.

_Cette classe simule la loi passée en paramètre (e.g. `CVanillaOptionBS`) via polymorphisme._

## 4) Interface utilisateur

La classe **CInterfacePricer** gère l'interaction utilisateur en ligne de commande :
- Choix d'un Call (C) ou Put (P)
- Saisie de `T`, `S0`, `r`, `sigma`, `K`, `NMC`
- Validation et vérification des paramètres
- Exécution du pricing (B&S + Monte-Carlo)
- Affichage des résultats

> _Attention_ : les volatilités et taux sont en base 1, la maturité en années.

## 5) Exemples d'utilisation

<p align="center">
 <img src="Image/Capture1.png" width="350">
</p>
<p align="center">
 Figure 1: Exemple d'utilisation du code avec l'interface utilisateur
</p>

<p align="center">
 <img src="Image/Capture2.png" width="350">
</p>
<p align="center">
 Figure 2: Exemple d'erreur de choix de paramètres
</p>
