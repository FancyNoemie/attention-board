# Le Jardin de l'attention et la technologie au ralenti 🌿🌱

Bienvenue dans la documentation du *Jardin de l'attention* ! Un **gros merci** pour votre participation au projet, je continue d'y travailler très fort! Vous trouverez ici toutes les informations qui expliquent comment l'appareil fonctionne, mais aussi des méthodes pour régler les paramètres, comment aller plus loin et vous approprier cet outil. Il me ferait vraiment plaisir d'avoir de vos nouvelles dans le volet **discussion** du GitHub, que ce soit pour partager des commentaires, des idées ou des problèmes. 

S'il manque quelque chose, faitez moi signe! la documentation est en constante construction!

Merci à Chantale Cyr, Jacob Johnston, Peter Flemming, Elio Bidinost et Brad Todd, ce fut un plaisir de collaborer avec des gens aussi exceptionnels, et sans votre soutien le projet n'aurait jamais vu le jour!

![20241101_142848 1](https://github.com/user-attachments/assets/78811052-2516-487a-8aab-27f91342e189)

--------------
## Table des matières
### - Programmer le microcontrolleur 🧠
>Quel est le but de l'atelier, les idées qu'on y a partagé?
>Qu'est ce que je fait avec cet objet là?
>Un peu de technicalitées pour savoir exactement à quoi j'ai affaire.
### - Étape 1 - Arduino IDE ⚙️
> Qu'est ce que c'est un Arduino?
> Comment ça fonctionne? Comment y accéder, lire et comprendre le code?
### - Étape 2 - Le pilote (*driver*) CH340 🔧
> 
### - Étape 3 - Connection 🔌
> Comment ça fonctionne? Comment y accéder, lire et comprendre le code? Est ce que je peux le changer?
### - Étape 4 - Télécharger un code 🗝️
> Par où commencer pour modifier le code? Changer les délais, les sons, les réactions?
> Quelles sont les possibilitées?
> Quelles sont les ressources vers lesquelles me tourner?
### - Bonus - Rétablir le code original ✨
> Par où commencer pour modifier le code? Changer les délais, les sons, les réactions?
> Quelles sont les possibilitées?

------

# Programmer le microcontrolleur 🧠
Notre Jardin de l'attention est contrôlé par notre composante bleue avec toutes les petites pattes: le Arduino Nano. C'est cette petite composante qui recois l'information, fait les calculs et allume les lumières. Ensemble, on a programmé nos arduino avec une suite d'instruction que j'ai écrite, mais il est tout a fait possible de changer les réactions de notre Jardin de l'attention! Pour ça, tu peut changer la suite d'instructions que j'ai fait, ou en rédiger une nouvelle. Même si tu fait des expérimentations, **tu pourras toujours revenir au code original**. Pour chaque version du jardin de l'attention, j'ai partagé un code. Voyons comment l'installer! n'hésite pas a demander de l'aide si tu as de la difficulté.

### Tu aura besoin de : 
> - Ton jardin de l'attention
> - Un fil d'alimentation USB
> - Un ordinateur

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
Si tu n'a pas réussi à établir la connection, voici une liste de pistes de solutions à tester.
> - L'arduino a une lumière allumée qui nous montre que c'est bien connecté à notre ordinateur.
> - Le port usb est bien le bon
> - changer le bootloader
> - vérifier avec un fil d'alimentation différent
> - code non compilé

# Étape 4 - Télécharger un code 🗝️
Si tout va bien, tu devrait être en mesure 

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

# Bonus - Rétablir le code original ✨
