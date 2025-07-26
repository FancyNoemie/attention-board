# Le Jardin de l'attention et la technologie au ralenti 🌿🌱

Bienvenue dans la documentation du *Jardin de l'attention* ! Un **gros merci** pour votre participation au projet, je continue d'y travailler très fort! Vous trouverez ici toutes les informations qui expliquent comment l'appareil fonctionne, mais aussi des méthodes pour régler les paramètres, comment aller plus loin et vous approprier cet outil. Il me ferait vraiment plaisir d'avoir de vos nouvelles dans le volet **discussion** du GitHub, que ce soit pour partager des commentaires, des idées ou des problèmes. 

S'il manque quelque chose, faitez moi signe! la documentation est en constante construction!

Merci à Chantale Cyr, Jacob Johnston, Peter Flemming, Elio Bidinost et Brad Todd, ce fut un plaisir de collaborer avec des gens aussi exceptionnels, et sans votre soutien le projet n'aurait jamais vu le jour!

![20241101_142848 1](https://github.com/user-attachments/assets/78811052-2516-487a-8aab-27f91342e189)

***Classe de Mme Judith, novembre 2024***

------

# Programmer le microcontrolleur 🧠
Notre Jardin de l'attention est contrôlé par notre composante bleue avec toutes les petites pattes: le Arduino Nano. C'est cette composante qui reçois l'information, fait les calculs et allume les lumières. Ensemble, on a programmé nos arduino avec une suite d'instruction que j'ai écrite, mais il est tout a fait possible de changer les réactions de notre Jardin de l'attention! Pour ça, tu peut changer la suite d'instructions que j'ai fait, ou en rédiger une nouvelle. Même si tu fait des expérimentations, **tu pourras toujours revenir au code original**. Pour chaque version du jardin de l'attention, j'ai partagé un code. Voyons comment l'installer! n'hésite pas a demander de l'aide si tu as de la difficulté.

**Tu aura besoin de :** 
> - Ton jardin de l'attention
> - Un fil d'alimentation USB
> - Un ordinateur

## Table des matières

**Étape 1 - Arduino IDE ⚙️**</br>
> Qu'est ce que c'est un Arduino?
> Comment ça fonctionne? Comment y accéder, lire et comprendre le code?

**Étape 2 - Le pilote (*driver*) CH340 🔧**</br>
> Préparer notre ordinateur à notre microcontrolleur.

**Étape 3 - Connection 🔌**</br>
> Tout brancher pour établir une première communication entre mon microcontrolleur et le logiciel.

**Étape 4 - Télécharger un code 🗝️**</br>
> Par où commencer pour modifier le code? Changer les délais, les sons, les réactions?
> Quelles sont les possibilitées?
> Quelles sont les ressources vers lesquelles me tourner?

**Bonus - Rétablir le code original ✨**</br>
> Comment installer ou réinstaller le code original de notre jardin de l'attention.
> Changer les délais de nos bouttons

-----

# Étape 1 - Arduino IDE ⚙️
Installer le logiciel pour pouvoir coder!
Une fois installé, tu pourra établir une communication avec ton microcontroleur... et le reprogrammer! J'ai intallé la version 2.3.1, car c'est la version la plus récente, mais tu peux installer la version la plus récente pour toi. Ensuite, tu pourra sélectionner le système d’exploitation de ton ordinateur (*Windows, MacOS ou Linux*).
> https://www.arduino.cc/en/software/

# Étape 2 - Le pilote (*driver*) CH340 🔧
Notre microcontroleur est un clone, une version moins cher du arduino nano classique. Pour qu'il fonctionne, on va devoir installer le pilote (*driver*) approprié. Tu auras à faire cette étape une seule fois pour ton ordinateur.
Pour être plus exacte: Le pilote (*driver*) **CH340** est un composant logiciel qui permet à votre ordinateur de communiquer avec des périphériques à l'aide de la puce USB-série CH340, que l'on trouve couramment dans diverses cartes compatibles Arduino. Tu peut trouver le lien du fabricant ici... mais je te met aussi le fichier ci-dessous. https://www.wch.cn/downloads/CH341SER_ZIP.html 
> https://www.wch.cn/download/file?id=5
> - suivre les instructions d'installation.

# Étape 3 - Connection 🔌
Il est maintenant temps de connecter le microcontrolleur à notre ordinateur! Commence par le brancher à un des port USB de ton ordinateur, puis nous auront à établir la connection sur notre logiciel de code.
> Sélectionne le bon port dans la liste
> Sélectionne le modèle de notre microcontrolleur (arduino)
> Test la connection avec aucune lignes de code (pour vérifier si tout va bien)

### Identifier un problème
Si tu n'a pas réussi à établir la connection, voici une liste de pistes de solutions pour aider à identifier un problème. Commence par vérifier que tout est beau quand tu appuie sur le bouton ✔️ pour compiler ton code dans arduino. Si tu vois déjà une erreur, le problème est dans le code.
> - L'arduino doit avoir une lumière allumée qui nous montre qu'il est bien connecté à une souce d'énergie (notre ordinateur).
> - Le port usb est bien le bon. Il peut y avoir beaucoup d'options de ports disponibles via le logiciel...
> - Changer le bootloader
> - Vérifier avec un fil d'alimentation différent. Certains fils ne sont fait que pour partager de l'énergie, pas des données. 

# Étape 4 - Télécharger un code 🗝️
Si tout va bien, tu devrait être en mesure d'effacer le contenu de ton fichier arduino et d'y coller un exemple. Tester une composante à la fois est toujours une bonne idée!

> Voici un exemple simple, qui fait tamiser la lumière connectée à la *pin* 9 de notre arduino. Dans notre cas, c'est la lumière au centre de notre jardin de l'attention.
```
int led = 9;         // the PWM pin the LED is attached to
int brightness = 0;  // how bright the LED is
int fadeAmount = 5;  // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 9:
  analogWrite(led, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}
```

# Rétablir le code original ✨
  
**Déterminer la version**
Tu ne remarquera pas de grosse différence entre les deux versions du code, mais tu verra que les chemins, les circuits imprimés sont différents d'une version du circuit imprimé à l'autre. J'en ai profité pour régler de petits problèmes. Les composantes sont presque identiques d'une version à l'autre, mais la plaque verte, mon circuit imprimé, sera différent.

| Version 1      | Version 2      |
| :-------------: | :-------------: |
| <a href="url"><img title="Version 1" alt="Jardin de l'attention version 1: lumières bleues résistances lignées." src="https://github.com/user-attachments/assets/2cad1b51-6a07-47e5-9c7b-58ac1d23c5e2" ></a> | <a href="url"><img title="Version 1" alt="Jardin de l'attention version 1: lumières bleues résistances lignées." src="https://github.com/user-attachments/assets/2cad1b51-6a07-47e5-9c7b-58ac1d23c5e2" ></a> |
| Voici la toute première version du jardin de l'attention, avec des lumières rondes, bleues et des résistances lignées. | Voici la deuxième version du jardin de l'attention, avec ses toutes petites lumières vertes.|
| <a href="url">Télécharge ce fichier</a> | <a href="url">Télécharge ce fichier</a> |


# Bonus - Musique
**3-3-4-5-5-4-3-2-1-1-2-3-3-2-2**</br>
**3-3-4-5-5-4-3-2-1-1-2-3-2-1-1**
