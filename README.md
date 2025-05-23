# Le Jardin de l'attention et la technologie au ralenti 🌿

Bienvenue dans la documentation du *Jardin de l'attention* ! Un **gros merci** pour votre participation au projet, je continue d'y travailler très fort! Vous trouverez ici toutes les informations qui expliquent comment l'appareil fonctionne, mais aussi des méthodes pour régler les paramètres, comment aller plus loin et vous approprier cet outil. Il me ferait vraiment plaisir d'avoir de vos nouvelles dans le volet **discussion** du GitHub, que ce soit pour partager des commentaires, des idées ou des problèmes. 

S'il manque quelque chose, faitez moi signe! la documentation est en constante construction!

Merci à Chantale Cyr, Jacob Johnston, Peter Flemming, Elio Bidinost et Brad Todd, ce fut un plaisir de collaborer avec des gens aussi exceptionnels, et sans votre soutien le projet n'aurait jamais vu le jour!

--------------
## Table des matières
### - Le projet 📖
>Quel est le but de l'atelier, les idées qu'on y a partagé?
>Qu'est ce que je fait avec cet objet là? 
### - Les composantes ⚙️
> Électrique... Électronique... c'est quoi ca?
> Un peu de technicalitées pour savoir exactement à quoi j'ai affaire.
### - Le microcontrolleur 🧠
> Qu'est ce que c'est un Arduino?
### - Le code 🗝️
> Comment ça fonctionne? Comment y accéder, lire et comprendre le code? Est ce que je peux le changer?
### - Pour aller plus loin 🎁
> Par où commencer pour modifier le code? Changer les délais, les sons, les réactions?
> Quelles sont les possibilitées?
> Quelles sont les ressources vers lesquelles me tourner?

------

# Le microcontrolleur
Notre Jardin de l'attention est contrôlé par notre composante avec toutes les petites pattes: le Arduino Nano. C'est cette petite composante qui recois l'information, fait les calculs et allume les lumières. Ensemble, on a programmé nos arduino avec une suite d'instruction que j'ai écrite, mais il est tout a fait possible de changer les réactions de notre Jardin de l'attention! Pour ça, tu peut changer la suite d'instructions que j'ai fait, ou en rédiger une nouvelle. Même si tu fait des expérimentations, tu pourras toujours revenir au code original. Pour chaque version du jardin de l'attention, j'ai partagé un code. Voyons comment l'installer! n'hésite pas a demander de l'aide si tu as de la difficulté.

Tu aura besoin de : 
> - Ton jardin de l'attention
> - Un fil d'alimentation USB
> - Un ordinateur

## Étape 1
Installer le logiciel pour pouvoir coder!
Une fois installé, tu pourra établir une communication avec ton microcontroleur... et le reprogrammer! J'ai intallé la version 2.3.1, car c'est la version la plus récente, mais tu peux installer la version la plus récente pour toi. Ensuite, tu pourra sélectionner le système d’exploitation de ton ordinateur (*Windows, MacOS ou Linux*).
> https://www.arduino.cc/en/software/

## Étape 2
Notre microcontroleur est un clone, une version moins cher du arduino nano classique. Pour qu'il fonctionne, on va devoir installer le pilote (*driver*) approprié. Tu auras à faire cette étape une seule fois pour ton ordinateur.
Pour être plus exacte: Le pilote (*driver*) **CH340** est un composant logiciel qui permet à votre ordinateur de communiquer avec des périphériques à l'aide de la puce USB-série CH340, que l'on trouve couramment dans diverses cartes compatibles Arduino. Tu peut trouver le lien du fabricant ici... mais je te met aussi le fichier ci-dessous. https://www.wch.cn/downloads/CH341SER_ZIP.html 
> https://www.wch.cn/download/file?id=5


