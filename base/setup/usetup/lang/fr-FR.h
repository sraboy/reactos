#pragma once

MUI_LAYOUTS frFRLayouts[] =
{
    { L"040C", L"0000040C" },
    { L"0409", L"00000409" },
    { NULL, NULL }
};

static MUI_ENTRY frFRLanguagePageEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "S�lection de la langue.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        10,
        "\x07  Veuiller choisir la langue utilis�e pour le processus d'installation",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        11,
        "   et appuyer sur ENTR�E.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        13,
        "\x07  Cette langue sera la langue par d�faut pour le syst�me final.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "ENTR�E = Continuer  F3 = Quitter",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY frFRWelcomePageEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "Bienvenue dans l'installation de ReactOS",
        TEXT_STYLE_HIGHLIGHT
    },
    {
        6,
        11,
        "Cette partie de l'installation copie le Syst�me d'Exploitation ReactOS",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        12,
        "sur votre ordinateur et le pr�pare � la 2e partie de l'installation.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        15,
        "\x07  Appuyer sur ENTR�E pour installer ReactOS.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        17,
        "\x07  Appuyer sur R pour r�parer ReactOS.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        19,
        "\x07  Appuyer sur L pour les Termes et Conditions de Licence ReactOS",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        21,
        "\x07  Appuyer sur F3 pour quitter sans installer ReactOS.",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        23,
        "Pour plus d'informations sur ReactOS, veuiller visiter :",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        24,
        "http://www.reactos.org",
        TEXT_STYLE_HIGHLIGHT
    },
    {
        0,
        0,
        "ENTR�E = Continuer  R = R�parer  L = Licence  F3 = Quitter",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY frFRIntroPageEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " Setup ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "ReactOS Version Status",
        TEXT_STYLE_HIGHLIGHT
    },
    {
        6,
        11,
        "ReactOS is in Alpha stage, meaning it is not feature-complete",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        12,
        "and is under heavy development. It is recommended to use it only for",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        13,
        "evaluation and testing purposes and not as your daily-usage OS.",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        15,
        "Backup your data or test on a secondary computer if you attempt",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        16,
        "to run ReactOS on real hardware.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        19,
        "\x07  Press ENTER to continue ReactOS Setup.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        21,
        "\x07  Press F3 to quit without installing ReactOS.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "ENTER = Continue   F3 = Quit",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY frFRLicensePageEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        6,
        "Licence :",
        TEXT_STYLE_HIGHLIGHT
    },
    {
        8,
        8,
        "The ReactOS System is licensed under the terms of the",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        9,
        "GNU GPL with parts containing code from other compatible",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        10,
        "licenses such as the X11 or BSD and GNU LGPL licenses.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        11,
        "All software that is part of the ReactOS system is",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        12,
        "therefore released under the GNU GPL as well as maintaining",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        13,
        "the original license.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        15,
        "This software comes with NO WARRANTY or restrictions on usage",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        16,
        "save applicable local and international law. The licensing of",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        17,
        "ReactOS only covers distribution to third parties.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        18,
        "If for some reason you did not receive a copy of the",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        19,
        "GNU General Public License with ReactOS please visit",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        20,
        "http://www.gnu.org/licenses/licenses.html",
        TEXT_STYLE_HIGHLIGHT
    },
    {
        8,
        22,
        "Garantie :",
        TEXT_STYLE_HIGHLIGHT
    },
    {
        8,
        24,
        "This is free software; see the source for copying conditions.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        25,
        "There is NO warranty; not even for MERCHANTABILITY or",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        26,
        "FITNESS FOR A PARTICULAR PURPOSE",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "ENTR�E = Retour",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY frFRDevicePageEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "La liste ci-dessous montre les r�glages mat�riels actuels.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        11,
        "     Ordinateur :",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        12,
        "      Affichage :",
        TEXT_STYLE_NORMAL,
    },
    {
        8,
        13,
        "        Clavier :",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        14,
        "R�glage Clavier :",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        16,
        "       Accepter :",
        TEXT_STYLE_NORMAL
    },
    {
        25,
        16, "Accepter ces r�glages mat�riels",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        19,
        "Vous pouvez changer les r�glages mat�riels en appuyant sur HAUT ou BAS",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        20,
        "pour s�lectionner une entr�e.",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        21,
        "Appuyer sur ENTR�E pour choisir un autre r�glage.",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        23,
        "Quand tous les r�glages sont corrects, s�lectionner \"Accepter",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        24,
        "ces r�glages mat�riels\" et appuyer sur ENTR�E.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "ENTR�E = Continuer   F3 = Quitter",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY frFRRepairPageEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "L'installation de ReactOS est en phase de d�veloppement.",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        9,
        "Elle ne supporte pas encore toutes les fonctions d'une application",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        10,
        "d'installation enti�rement utilisable.",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        12,
        "Les fonctions de r�paration ne sont pas impl�ment�es pour l'instant.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        15,
        "\x07  Appuyer sur U pour mettre � jour l'OS.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        17,
        "\x07  Appuyer sur R pour la Console de R�paration.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        19,
        "\x07  Appuyer sur �CHAP pour retourner � la page principale.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        21,
        "\x07  Appuyer sur ENTR�E pour red�marrer votre ordinateur.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "�CHAP = Page principale  ENTR�E = Red�marrer",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY frFRComputerPageEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "Vous voulez changer le type d'ordinateur install�.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        10,
        "\x07  Appuyer sur HAUT ou BAS pour s�lectionner le type d'ordinateur.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        11,
        "   Puis appuyer sur ENTR�E.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        13,
        "\x07  Appuyer sur �CHAP pour revenir � la page pr�c�dente sans changer",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        14,
        "   le type d'ordinateur.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "ENTR�E = Continuer   �CHAP = Annuler   F3 = Quitter",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY frFRFlushPageEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        10,
        6,
        "Le syst�me s'assure que toutes les donn�es sont �crites sur le disque",
        TEXT_STYLE_NORMAL
    },
    {
        10,
        8,
        "Cela peut prendre une minute",
        TEXT_STYLE_NORMAL
    },
    {
        10,
        9,
        "Quand cela sera fini, votre ordinateur red�marrera automatiquement",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "Vidage du cache",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY frFRQuitPageEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        10,
        6,
        "ReactOS n'est pas compl�tement install�",
        TEXT_STYLE_NORMAL
    },
    {
        10,
        8,
        "Enlever la disquette du lecteur A: et",
        TEXT_STYLE_NORMAL
    },
    {
        10,
        9,
        "tous les CDROMs des lecteurs de CD.",
        TEXT_STYLE_NORMAL
    },
    {
        10,
        11,
        "Appuyer sur ENTR�E pour red�marrer votre ordinateur.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "Veuillez attendre ...",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY frFRDisplayPageEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "Vous voulez changer le type d'�cran � installer.",
        TEXT_STYLE_NORMAL
    },
    {   8,
        10,
         "\x07  Appuyer sur HAUT ou BAS pour s�lectionner le type d'�cran.",
         TEXT_STYLE_NORMAL
    },
    {
        8,
        11,
        "   Appuyer sur ENTR�E.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        13,
        "\x07  Appuyer sur �CHAP pour revenir � la page pr�c�dente sans changer",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        14,
        "   le type d'�cran.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "ENTR�E = Continuer   �CHAP = Annuler   F3 = Quitter",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY frFRSuccessPageEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        10,
        6,
        "Les composants standards de ReactOS ont �t� install�s avec succ�s.",
        TEXT_STYLE_NORMAL
    },
    {
        10,
        8,
        "Enlever la disquette du lecteur A: et",
        TEXT_STYLE_NORMAL
    },
    {
        10,
        9,
        "tous les CDROMs des lecteurs de CD.",
        TEXT_STYLE_NORMAL
    },
    {
        10,
        11,
        "Appuyer sur ENTR�E pour red�marrer votre ordinateur.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "ENTR�E = Red�marrer l'ordinateur",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY frFRBootPageEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "Setup ne peut installer le chargeur sur le disque dur",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        9,
        "de votre ordinateur",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        13,
        "Veuillez ins�rer une disquette format�e dans le lecteur A: et",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        14,
        "appuyer sur ENTR�E.",
        TEXT_STYLE_NORMAL,
    },
    {
        0,
        0,
        "ENTR�E = Continuer   F3 = Quitter",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }

};

static MUI_ENTRY frFRSelectPartitionEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "La liste suivante montre les partitions existantes et",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        9,
        "l'espace disque non utilis� pour de nouvelles partitions.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        11,
        "\x07  Appuyer sur HAUT ou BAS pour s�lectionner une entr�e de la liste.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        13,
        "\x07  Appuyer sur ENTR�E pour installer ReactOS sur la partition choisie.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        15,
        "\x07  Appuyer sur P pour cr�er une partition primaire.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        17,
        "\x07  Appuyer sur E pour cr�er une partition �tendue.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        19,
        "\x07  Appuyer sur L pour cr�er une partition logique.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        21,
        "\x07  Appuyer sur D pour effacer une partition.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "Patienter...",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY frFRConfirmDeleteSystemPartitionEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "Vous avez choisi de supprimer la partition syst�me.",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        10,
        "La partition syst�me peut contenir des programmes de diagnostic, de",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        11,
        "configuration du mat�riel, des programmes pour d�marrer un syst�me",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        12,
        "d'exploitation (comme ReactOS) ou d'autres programmes fournis par le",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        13,
        "constructeur du mat�riel.",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        15,
        "Ne supprimez la partition syst�me que si vous �tes s�r qu'il n'y a aucun",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        16,
        "programme dans la partition, ou bien si vous souhaitez les supprimer.",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        17,
        "Lorsque vous supprimez la partition syst�me, vous ne pourrez peut-�tre",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        18,
        "plus d�marrer votre ordinateur depuis le disque dur jusqu'� ce que vous",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        19,
        "finissiez l'installation de ReactOS.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        22,
        "\x07  Appuyer sur ENTR�E pour supprimer la partition syst�me. Il vous sera",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        23,
        "   demand� de confirmer la suppression de la partition plus tard.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        26,
        "\x07  Appuyer sur �CHAP pour retourner � la page principale. La partition",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        27,
        "   ne sera pas supprim�e.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "ENTR�E = Continuer  �CHAP = Annuler",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY frFRFormatPartitionEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "Formater la partition",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        10,
        "Setup va formater la partition. Appuyer sur ENTR�E pour continuer.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "ENTR�E = Continuer   F3 = Quitter",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        TEXT_STYLE_NORMAL
    }
};

static MUI_ENTRY frFRInstallDirectoryEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "Setup installe les fichiers de ReactOS sur la partition s�lectionn�e.",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        9,
        "Choisissez un repertoire o� vous voulez que ReactOS soit install� :",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        14,
        "Pour changer le r�pertoire propos�, appuyez sur BACKSPACE pour effacer",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        15,
        "des caract�res et ensuite tapez le r�pertoire ou vous voulez que",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        16,
        "ReactOS soit install�",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "ENTR�E = Continuer   F3 = Quitter",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY frFRFileCopyEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        11,
        12,
        "Patientez pendant que ReactOS Setup copie les fichiers",
        TEXT_STYLE_NORMAL
    },
    {
        15,
        13,
        "dans le r�pertoire d'installation de ReactOS.",
        TEXT_STYLE_NORMAL
    },
    {
        20,
        14,
        "Cela peut prendre plusieurs minutes.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "                                                           \xB3 Patientez...    ",
        TEXT_TYPE_STATUS
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY frFRBootLoaderEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "Setup installe le chargeur de d�marrage",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        12,
        "Installer le chargeur de d�marrage sur le disque dur (MBR et VBR).",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        13,
        "Installer le chargeur de d�marrage sur le disque dur (VBR seulement).",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        14,
        "Installer le chargeur de d�marrage sur une disquette.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        15,
        "Ne pas installer le chargeur de d�marrage.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "ENTR�E = Continuer   F3 = Quitter",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY frFRKeyboardSettingsEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "Vous voulez changer le type de clavier � installer.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        10,
        "\x07  Appuyez sur HAUT ou BAS pour s�lectionner le type de clavier,",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        11,
        "   puis appuyez sur ENTR�E.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        13,
        "\x07  Appuyez sur �CHAP pour revenir � la page pr�c�dente sans changer",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        14,
        "   le type de clavier.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "ENTR�E = Continuer   �CHAP = Annuler   F3 = Quitter",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY frFRLayoutSettingsEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "Veuillez s�lectionner une disposition � installer par d�faut.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        10,
        "\x07  Appuyez sur HAUT ou BAS pour s�lectionner la disposition",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        11,
        "    choisie. Puis appuyez sur ENTR�E.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        13,
        "\x07  Appuyez sur �CHAP pour revenir � la page pr�c�dente sans changer",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        14,
        "   la disposition du clavier.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "ENTR�E = Continuer   �CHAP = Annuler   F3 = Quitter",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    },

};

static MUI_ENTRY frFRPrepareCopyEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "Setup pr�pare votre ordinateur pour copier les fichiers de ReactOS. ",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "Pr�pare la liste de fichiers � copier...",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    },

};

static MUI_ENTRY frFRSelectFSEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        17,
        "S�lectionnez un syst�me de fichiers dans la liste suivante.",
        0
    },
    {
        8,
        19,
        "\x07  Appuyez sur HAUT ou BAS pour s�lectionner un syst�me de fichiers.",
        0
    },
    {
        8,
        21,
        "\x07  Appuyez sur ENTR�E pour formater la partition.",
        0
    },
    {
        8,
        23,
        "\x07  Appuyez sur �CHAP pour s�lectionner une autre partition.",
        0
    },
    {
        0,
        0,
        "ENTR�E = Continuer   �CHAP = Annuler   F3 = Quitter",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },

    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY frFRDeletePartitionEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "Vous avez choisi de supprimer la partition",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        18,
        "\x07  Appuyez sur D pour supprimer la partition.",
        TEXT_STYLE_NORMAL
    },
    {
        11,
        19,
        "ATTENTION: Toutes les donne�es de cette partition seront perdues!",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        21,
        "\x07  Appuyez sur �CHAP pour annuler.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "D = Supprimer la Partition   �CHAP = Annuler   F3 = Quitter",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY frFRRegistryEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "Setup met � jour la configuration du syst�me. ",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "En train de cr�er la base de registres...",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    },

};

MUI_ERROR frFRErrorEntries[] =
{
    {
        // NOT_AN_ERROR
        "Succ�s\n"
    },
    {
        //ERROR_NOT_INSTALLED
        "ReactOS n'est pas compl�tement install� sur votre\n"
        "ordinateur. Si vous quittez Setup maintenant, vous devrez\n"
        "lancer Setup de nouveau pour installer ReactOS.\n"
        "\n"
        "  \x07  Appuyer sur ENTR�E pour continuer Setup.\n"
        "  \x07  Appuyer sur F3 pour quitter Setup.",
        "F3 = Quitter  ENTR�E = Continuer"
    },
    {
        //ERROR_NO_HDD
        "Setup n'a pu trouver un disque dur.\n",
        "ENTR�E = Red�marrer l'ordinateur"
    },
    {
        //ERROR_NO_SOURCE_DRIVE
        "Setup n'a pu trouver son lecteur source.\n",
        "ENTR�E = Red�marrer l'ordinateur"
    },
    {
        //ERROR_LOAD_TXTSETUPSIF
        "Setup n'a pas r�ussi � charger le fichier TXTSETUP.SIF.\n",
        "ENTR�E = Red�marrer l'ordinateur"
    },
    {
        //ERROR_CORRUPT_TXTSETUPSIF
        "Setup a trouv� un fichier TXTSETUP.SIF corrompu.\n",
        "ENTR�E = Red�marrer l'ordinateur"
    },
    {
        //ERROR_SIGNATURE_TXTSETUPSIF,
        "Setup a trouv� une signature invalide dans TXTSETUP.SIF.\n",
        "ENTR�E = Red�marrer l'ordinateur"
    },
    {
        //ERROR_DRIVE_INFORMATION
        "Setup n'a pu r�cup�rer les informations du disque syst�me.\n",
        "ENTR�E = Red�marrer l'ordinateur"
    },
    {
        //ERROR_WRITE_BOOT,
        "Echec de l'installation du code de d�marrage FAT sur la partition syst�me.",
        "ENTR�E = Red�marrer l'ordinateur"
    },
    {
        //ERROR_LOAD_COMPUTER,
        "Setup n'a pu charger la liste de type d'ordinateurs.\n",
        "ENTR�E = Red�marrer l'ordinateur"
    },
    {
        //ERROR_LOAD_DISPLAY,
        "Setup n'a pu charger la liste de r�glages des �crans.\n",
        "ENTR�E = Red�marrer l'ordinateur"
    },
    {
        //ERROR_LOAD_KEYBOARD,
        "Setup n'a pu charger la liste de types de claviers.\n",
        "ENTR�E = Red�marrer l'ordinateur"
    },
    {
        //ERROR_LOAD_KBLAYOUT,
        "Setup n'a pu charger la liste de dispositions de claviers.\n",
        "ENTR�E = Red�marrer l'ordinateur"
    },
    {
        //ERROR_WARN_PARTITION,
        "Setup a d�tect� qu'au moins un disque dur contient une table\n"
        "de partition incompatible qui ne peut �tre prise en compte!\n"
        "\n"
        "Cr�er ou effacer des partitions peut d�truire la table de partition.\n"
        "\n"
        "  \x07  Appuyer sur F3 pour quitter Setup.\n"
        "  \x07  Appuyer sur ENTR�E pour continuer Setup.",
        "F3 = Quitter  ENTR�E = Continuer"
    },
    {
        //ERROR_NEW_PARTITION,
        "Vous ne pouvez cr�er une nouvelle Partition � l'int�rieur\n"
        "d'une Partition d�j� existante!\n"
        "\n"
        "  * Appuyer sur une touche pour continuer.",
        NULL
    },
    {
        //ERROR_DELETE_SPACE,
        "Vous ne pouvez supprimer de l'espace disque non partitionn�!\n"
        "\n"
        "  * Appuyer sur une touche pour continuer.",
        NULL
    },
    {
        //ERROR_INSTALL_BOOTCODE,
        "Echec de l'installation du code de d�marrage FAT sur la partition syst�me.",
        "ENTR�E = Red�marrer l'ordinateur"
    },
    {
        //ERROR_NO_FLOPPY,
        "Pas de disque dans le lecteur A:.",
        "ENTR�E = Continuer"
    },
    {
        //ERROR_UPDATE_KBSETTINGS,
        "Setup n'a pu mettre � jour les r�glages de disposition du clavier.",
        "ENTR�E = Red�marrer l'ordinateur"
    },
    {
        //ERROR_UPDATE_DISPLAY_SETTINGS,
        "Setup n'a pu mettre � jour les r�glages de l'�cran.",
        "ENTR�E = Red�marrer l'ordinateur"
    },
    {
        //ERROR_IMPORT_HIVE,
        "Setup n'a pu importer un fichier ruche.",
        "ENTR�E = Red�marrer l'ordinateur"
    },
    {
        //ERROR_FIND_REGISTRY
        "Setup n'a pu trouver les fichiers de la base de registres.",
        "ENTR�E = Red�marrer l'ordinateur"
    },
    {
        //ERROR_CREATE_HIVE,
        "Setup n'a pu cr�er les ruches de la base de registres.",
        "ENTR�E = Red�marrer l'ordinateur"
    },
    {
        //ERROR_INITIALIZE_REGISTRY,
        "Setup n'a pu initialiser la base de registres.",
        "ENTR�E = Red�marrer l'ordinateur"
    },
    {
        //ERROR_INVALID_CABINET_INF,
        "Le Cabinet n'a pas de fichier inf valide.\n",
        "ENTR�E = Red�marrer l'ordinateur"
    },
    {
        //ERROR_CABINET_MISSING,
        "Cabinet non trouv�.\n",
        "ENTR�E = Red�marrer l'ordinateur"
    },
    {
        //ERROR_CABINET_SCRIPT,
        "Cabinet n'a pas de script de setup.\n",
        "ENTR�E = Red�marrer l'ordinateur"
    },
    {
        //ERROR_COPY_QUEUE,
        "Setup n'a pu ouvrir la file d'attente de copie de fichiers.\n",
        "ENTR�E = Red�marrer l'ordinateur"
    },
    {
        //ERROR_CREATE_DIR,
        "Setup n'a pu cr�er les r�pertoires d'installation.",
        "ENTR�E = Red�marrer l'ordinateur"
    },
    {
        //ERROR_TXTSETUP_SECTION,
        "Setup n'a pu trouver la section 'Directories'\n"
        "dans TXTSETUP.SIF.\n",
        "ENTR�E = Red�marrer l'ordinateur"
    },
    {
        //ERROR_CABINET_SECTION,
        "Setup n'a pu trouver la section 'Directories\n"
        "dans le cabinet.\n",
        "ENTR�E = Red�marrer l'ordinateur"
    },
    {
        //ERROR_CREATE_INSTALL_DIR
        "Setup n'a pu cr�er le r�pertoire d'installation.",
        "ENTR�E = Red�marrer l'ordinateur"
    },
    {
        //ERROR_FIND_SETUPDATA,
        "Setup n'a pu trouver la section 'SetupData'\n"
        "dans TXTSETUP.SIF.\n",
        "ENTR�E = Red�marrer l'ordinateur"
    },
    {
        //ERROR_WRITE_PTABLE,
        "Setup n'a pu �crire les tables de partition.\n"
        "ENTR�E = Red�marrer l'ordinateur"
    },
    {
        //ERROR_ADDING_CODEPAGE,
        "Setup n'a pu ajouter la page de codes � la base de registres.\n"
        "ENTR�E = Red�marrer l'ordinateur"
    },
    {
        //ERROR_UPDATE_LOCALESETTINGS,
        "Setup n'a pu changer la langue syst�me.\n"
        "ENTR�E = Red�marrer l'ordinateur"
    },
    {
        //ERROR_ADDING_KBLAYOUTS,
        "Setup n'a pas pu ajouter les dispositions de clavier au registre.\n"
        "ENTR�E = Red�marrer l'ordinateur"
    },
    {
        //ERROR_UPDATE_GEOID,
        "Setup n'a pas pu d�finir la geo id.\n"
        "ENTR�E = Red�marrer l'ordinateur"
    },
    {
        //ERROR_DIRECTORY_NAME,
        "Nom de r�pertoire invalide.\n"
        "\n"
        "  * Appuyer sur une touche pour continuer."
    },
    {
        //ERROR_INSUFFICIENT_PARTITION_SIZE,
        "The selected partition is not large enough to install ReactOS.\n"
        "The install partition must have a size of at least %lu MB.\n"
        "\n"
        "  * Appuyer sur une touche pour continuer.",
        NULL
    },
    {
        //ERROR_PARTITION_TABLE_FULL,
        "Impossible de cr�er une nouvelle partition primaire ou �tendue\n"
        "sur ce disque parce que sa table de partition est pleine.\n"
        "\n"
        "  * Appuyer sur une touche pour continuer."
    },
    {
        //ERROR_ONLY_ONE_EXTENDED,
        "Impossible de cr�er plus d'une partition �tendue par disque.\n"
        "\n"
        "  * Appuyer sur une touche pour continuer."
    },
    {
        //ERROR_FORMATTING_PARTITION,
        "Setup is unable to format the partition:\n"
        " %S\n"
        "\n"
        "ENTER = Reboot computer"
    },
    {
        NULL,
        NULL
    }
};

MUI_PAGE frFRPages[] =
{
    {
        LANGUAGE_PAGE,
        frFRLanguagePageEntries
    },
    {
        START_PAGE,
        frFRWelcomePageEntries
    },
    {
        INSTALL_INTRO_PAGE,
        frFRIntroPageEntries
    },
    {
        LICENSE_PAGE,
        frFRLicensePageEntries
    },
    {
        DEVICE_SETTINGS_PAGE,
        frFRDevicePageEntries
    },
    {
        REPAIR_INTRO_PAGE,
        frFRRepairPageEntries
    },
    {
        COMPUTER_SETTINGS_PAGE,
        frFRComputerPageEntries
    },
    {
        DISPLAY_SETTINGS_PAGE,
        frFRDisplayPageEntries
    },
    {
        FLUSH_PAGE,
        frFRFlushPageEntries
    },
    {
        SELECT_PARTITION_PAGE,
        frFRSelectPartitionEntries
    },
    {
        CONFIRM_DELETE_SYSTEM_PARTITION_PAGE,
        frFRConfirmDeleteSystemPartitionEntries
    },
    {
        SELECT_FILE_SYSTEM_PAGE,
        frFRSelectFSEntries
    },
    {
        FORMAT_PARTITION_PAGE,
        frFRFormatPartitionEntries
    },
    {
        DELETE_PARTITION_PAGE,
        frFRDeletePartitionEntries
    },
    {
        INSTALL_DIRECTORY_PAGE,
        frFRInstallDirectoryEntries
    },
    {
        PREPARE_COPY_PAGE,
        frFRPrepareCopyEntries
    },
    {
        FILE_COPY_PAGE,
        frFRFileCopyEntries
    },
    {
        KEYBOARD_SETTINGS_PAGE,
        frFRKeyboardSettingsEntries
    },
    {
        BOOT_LOADER_PAGE,
        frFRBootLoaderEntries
    },
    {
        LAYOUT_SETTINGS_PAGE,
        frFRLayoutSettingsEntries
    },
    {
        QUIT_PAGE,
        frFRQuitPageEntries
    },
    {
        SUCCESS_PAGE,
        frFRSuccessPageEntries
    },
    {
        BOOT_LOADER_FLOPPY_PAGE,
        frFRBootPageEntries
    },
    {
        REGISTRY_PAGE,
        frFRRegistryEntries
    },
    {
        -1,
        NULL
    }
};

MUI_STRING frFRStrings[] =
{
    {STRING_PLEASEWAIT,
     "   Veuillez patienter..."},
    {STRING_INSTALLCREATEPARTITION,
     "   ENTR�E = Installer   P/E = Cr�er Partition Primaire/�tendue   F3 = Quitter"},
    {STRING_INSTALLCREATELOGICAL,
     "   ENTR�E = Installer   L = Cr�er Partition Logique   F3 = Quitter"},
    {STRING_INSTALLDELETEPARTITION,
     "   ENTR�E = Installer   D = Supprimer Partition   F3 = Quitter"},
    {STRING_DELETEPARTITION,
     "   D = Supprimer Partition   F3 = Quitter"},
    {STRING_PARTITIONSIZE,
     "Taille de la nouvelle partition :"},
    {STRING_CHOOSENEWPARTITION,
     "Vous avez choisi de cr�er une partition primaire sur"},
    {STRING_CHOOSE_NEW_EXTENDED_PARTITION,
     "Vous avez choisi de cr�er une partition �tendue sur"},
    {STRING_CHOOSE_NEW_LOGICAL_PARTITION,
     "Vous avez choisi de cr�er une partition logique sur"},
    {STRING_HDDSIZE,
    "Veuillez entrer la taille de la nouvelle partition en m�gaoctets."},
    {STRING_CREATEPARTITION,
     "   ENTR�E = Cr�er Partition   �CHAP = Annuler   F3 = Quitter"},
    {STRING_PARTFORMAT,
    "Cette Partition sera ensuite format�e."},
    {STRING_NONFORMATTEDPART,
    "Vous avez choisi d'installer ReactOS sur une nouvelle partition."},
    {STRING_NONFORMATTEDSYSTEMPART,
    "The system partition is not formatted yet."},
    {STRING_NONFORMATTEDOTHERPART,
    "The new partition is not formatted yet."},
    {STRING_INSTALLONPART,
    "Setup installe ReactOS sur la partition"},
    {STRING_CHECKINGPART,
    "Setup v�rifie la partition s�lectionn�e."},
    {STRING_CONTINUE,
    "ENTR�E = Continuer"},
    {STRING_QUITCONTINUE,
    "F3 = Quitter  ENTR�E = Continuer"},
    {STRING_REBOOTCOMPUTER,
    "ENTR�E = Red�marrer l'ordinateur"},
    {STRING_TXTSETUPFAILED,
    "Setup n'a pu trouver la section '%S'\ndans TXTSETUP.SIF.\n"},
    {STRING_COPYING,
     "   Copie du fichier: %S"},
    {STRING_SETUPCOPYINGFILES,
     "Setup copie les fichiers..."},
    {STRING_REGHIVEUPDATE,
    "   Mise � jour de la base de registre..."},
    {STRING_IMPORTFILE,
    "   Importe %S..."},
    {STRING_DISPLAYETTINGSUPDATE,
    "   Mise � jour des param�tres du registre pour l'�cran..."},
    {STRING_LOCALESETTINGSUPDATE,
    "   Mise � jour des param�tres r�gionaux..."},
    {STRING_KEYBOARDSETTINGSUPDATE,
    "   Mise � jour des param�tres de la dispoition clavier..."},
    {STRING_CODEPAGEINFOUPDATE,
    "   Ajout des informations de pages de codes � la base de registres..."},
    {STRING_DONE,
    "   Termin�..."},
    {STRING_REBOOTCOMPUTER2,
    "   ENTR�E = Red�marrer l'ordinateur"},
    {STRING_CONSOLEFAIL1,
    "Impossible d'ouvrir la console\r\n\r\n"},
    {STRING_CONSOLEFAIL2,
    "La cause probable est l'utilisation d'un clavier USB\r\n"},
    {STRING_CONSOLEFAIL3,
    "Les claviers USB ne sont pas compl�tement support�s actuellement\r\n"},
    {STRING_FORMATTINGDISK,
    "Setup formate votre disque"},
    {STRING_CHECKINGDISK,
    "Setup v�rifie votre disque"},
    {STRING_FORMATDISK1,
    " Formater la partition comme syst�me de fichiers %S (formatage rapide) "},
    {STRING_FORMATDISK2,
    " Formater la partition comme syst�me de fichiers %S "},
    {STRING_KEEPFORMAT,
    " Garder le syst�me de fichiers courant (pas de changements) "},
    {STRING_HDINFOPARTCREATE,
    "%I64u %s  Disque dur %lu  (Port=%hu, Bus=%hu, Id=%hu) sur %wZ."},
    {STRING_HDDINFOUNK1,
    "%I64u %s  Disque dur %lu  (Port=%hu, Bus=%hu, Id=%hu)."},
    {STRING_HDDINFOUNK2,
    "   %c%c  Type 0x%02X    %I64u %s"},
    {STRING_HDINFOPARTDELETE,
    "sur %I64u %s  Disque dur %lu  (Port=%hu, Bus=%hu, Id=%hu) sur %wZ."},
    {STRING_HDDINFOUNK3,
    "sur %I64u %s  Disque dur %lu  (Port=%hu, Bus=%hu, Id=%hu)."},
    {STRING_HDINFOPARTZEROED,
    "Disque dur %lu (%I64u %s), Port=%hu, Bus=%hu, Id=%hu (%wZ)."},
    {STRING_HDDINFOUNK4,
    "%c%c  Type 0x%02X    %I64u %s"},
    {STRING_HDINFOPARTEXISTS,
    "sur Disque dur %lu (%I64u %s), Port=%hu, Bus=%hu, Id=%hu (%wZ)."},
    {STRING_HDDINFOUNK5,
    "%c%c %c %sType %-3u%s                      %6lu %s"},
    {STRING_HDINFOPARTSELECT,
    "%6lu %s  Disque dur %lu  (Port=%hu, Bus=%hu, Id=%hu) sur %S"},
    {STRING_HDDINFOUNK6,
    "%6lu %s  Disque dur %lu  (Port=%hu, Bus=%hu, Id=%hu)"},
    {STRING_NEWPARTITION,
    "Setup a cr�� une nouvelle partition sur"},
    {STRING_UNPSPACE,
    "    %sEspace non partitionn�%s            %6lu %s"},
    {STRING_MAXSIZE,
    "Mo (max. %lu Mo)"},
    {STRING_EXTENDED_PARTITION,
    "Partition �tendue"},
    {STRING_UNFORMATTED,
    "Nouveau (non format�)"},
    {STRING_FORMATUNUSED,
    "Non utilis�"},
    {STRING_FORMATUNKNOWN,
    "Inconnu"},
    {STRING_KB,
    "Ko"},
    {STRING_MB,
    "Mo"},
    {STRING_GB,
    "Go"},
    {STRING_ADDKBLAYOUTS,
    "Ajout des dispositions clavier"},
    {0, 0}
};
