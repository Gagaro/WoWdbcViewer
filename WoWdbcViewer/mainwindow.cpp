#include <QFileDialog>
#include <QSettings>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow  *MainWindow::getInstance()
{
    static MainWindow *instance = 0;

    if (!instance)
        instance = new MainWindow();
    return instance;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionLoad_dbc, SIGNAL(triggered()), this, SLOT(loadDbc()));
    connect(ui->buttonId, SIGNAL(clicked()), this, SLOT(lookupSpell()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadDbc()
{
    QSettings settings;
    QString directory;

    directory = QFileDialog::getExistingDirectory(this, "dbc directory", settings.value("viewer/dbc").toString());

    if (_spells.importSpells(directory))
    {
        settings.setValue("viewer/dbc", directory);
        statusBar()->showMessage("dbc loaded.", 10000);
        ui->inputId->setEnabled(true);
        ui->buttonId->setEnabled(true);
    }
    else
    {
        statusBar()->showMessage("Error while loading dbc.", 10000);
        ui->inputId->setEnabled(false);
        ui->buttonId->setEnabled(false);
    }
}

void MainWindow::lookupSpell()
{
    int id = ui->inputId->text().toInt();

    if (id <= 0)
    {
        statusBar()->showMessage("Invalid id.", 10000);
        return ;
    }

    const Spell * spell = (Spell *) 0;
    if ((spell = _spells.getSpell(id)) == 0)
    {
        statusBar()->showMessage("Unkown spell.", 10000);
        return ;
    }
    setSpellInformation(*spell);
}

void MainWindow::setSpellInformation(const Spell &spell)
{
    setSpellOverview(spell);
    setSpellAttributes(spell);
    setSpellEffects(spell);
}

void MainWindow::setSpellOverview(const Spell &spell)
{
    ui->listOverview->clear();
    ui->listOverview->addItem("Id: " + QString::number(spell.getId()));
    ui->listOverview->addItem("Name: " + spell.getName());
    ui->listOverview->addItem("Rank: " + spell.getRank());
    ui->listOverview->addItem("Description: " + spell.getDescription());
    ui->listOverview->addItem("Tooltip: " + spell.getTooltip());
    ui->listOverview->addItem("School: " + spell.getSchool());
    ui->listOverview->addItem("Range: from " + QString::number(spell.getMinRange())
                               + " to " + QString::number(spell.getMaxRange()));
    ui->listOverview->addItem("Dispel: " + spell.getDispel());
    ui->listOverview->addItem("Mechanic: " + spell.getMechanic());
}

void MainWindow::setSpellAttributes(const Spell &spell)
{
    QList<SpellAttribute>   attributes = spell.getAttributes();

    ui->listAttributesDesc->clear();
    for (int i = 0 ; i < attributes.size() ; i++)
    {
        ui->listAttributesDesc->addItem(attributes.at(i).getName() + ": " + attributes.at(i).getDescription());
    }
}

void MainWindow::setSpellEffects(const Spell &spell)
{
    QListWidget *listArray[] = {
        ui->listEffect1,
        ui->listEffect2,
        ui->listEffect3
    };

    for (int i = 0 ; i < MAX_EFFECT_INDEX ; i++)
    {
        const SpellEffect &s        = spell.getSpellEffect(i);
        QListWidget *list         = listArray[i];

        list->clear();
        if (s.getEffect() == SPELL_EFFECT_NONE)
        {
            ui->tabWidgetEffects->setTabEnabled(i, false);
            ui->tabWidgetEffects->setTabText(i, "None");
        }
        else
        {
            ui->tabWidgetEffects->setTabEnabled(i, true);
            ui->tabWidgetEffects->setTabText(i, s.getName());
            list->addItem("Effect id: " + QString::number(s.getEffect()));
            list->addItem("Die sides: " + QString::number(s.getDieSides()));
            list->addItem("Base dice: " + QString::number(s.getBaseDice()));
            list->addItem("Dice per level: " + QString::number(s.getDicePerLevel()));
            list->addItem("Real points per level: " + QString::number(s.getRealPointsPerLevel()));
            list->addItem("Base point: " + QString::number(s.getBasePoint()));
            list->addItem("Mechanic: " + QString::number(s.getMechanic()));
            list->addItem("Implicit target A: " + QString::number(s.getImplicitTargetA()));
            list->addItem("Implicit target B: " + QString::number(s.getImplicitTargetB()));
            list->addItem("Radius index: " + QString::number(s.getRadius()));
            list->addItem("Apply aura name: " + QString::number(s.getApplyAuraName()));
            list->addItem("Amplitude: " + QString::number(s.getAmplitude()));
            list->addItem("Multiple value: " + QString::number(s.getMultipleValue()));
            list->addItem("Chain target: " + QString::number(s.getChainTarget()));
            list->addItem("Item type: " + QString::number(s.getItemType()));
            list->addItem("Misc value: " + QString::number(s.getMiscValueA()));
            list->addItem("Misc value B: " + QString::number(s.getMiscValueB()));
            list->addItem("Trigger spell: " + QString::number(s.getTriggerSpell()));
            list->addItem("Points per combo point: " + QString::number(s.getPointsPerComboPoint()));
            list->addItem("Damage multiplier: " + QString::number(s.getDmgMultiplier()));
        }
    }
}
