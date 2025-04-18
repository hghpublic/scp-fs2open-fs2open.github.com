#pragma once

#include <QtWidgets/QDialog>
#include <QAbstractListModel>
#include <QItemSelectionModel>
#include <mission/dialogs/ShipEditor/ShipTextureReplacementDialogModel.h>

namespace fso {
	namespace fred {
		namespace dialogs {

			namespace Ui {
				class ShipTextureReplacementDialog;
			}
			//Model for mapping data to listview in Texture Replace dialog
			class MapModel : public QAbstractListModel
			{
				Q_OBJECT
			public:
				MapModel(ShipTextureReplacementDialogModel*, QObject* parent);
				int rowCount(const QModelIndex& parent = QModelIndex()) const override;
				QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
				ShipTextureReplacementDialogModel* _model;
			};

			class ShipTextureReplacementDialog : public QDialog {

				Q_OBJECT

			public:
				explicit ShipTextureReplacementDialog(QDialog* parent, EditorViewport* viewport, bool multiEdit);
				~ShipTextureReplacementDialog() override;
			protected:
				void closeEvent(QCloseEvent*) override;
			private:
				std::unique_ptr<Ui::ShipTextureReplacementDialog> ui;
				std::unique_ptr<ShipTextureReplacementDialogModel> _model;
				EditorViewport* _viewport;
				int row = 0;
				MapModel* listmodel;
				void updateUI();
				void updateUIFull();
				void rejectHandler();

				void setMain();
				void setMisc();
				void setGlow();
				void setShine();
				void setNormal();
				void setHeight();
				void setAo();
				void setReflect();

				void setMiscInherit(const bool state);
				void setGlowInherit(const bool state);
				void setShineInherit(const bool state);
				void setNormalInherit(const bool state);
				void setHeightInherit(const bool state);
				void setAoInherit(const bool state);
				void setReflectInherit(const bool state);

				void setMiscReplace(const bool state);
				void setGlowReplace(const bool state);
				void setShineReplace(const bool state);
				void setNormalReplace(const bool state);
				void setHeightReplace(const bool state);
				void setAoReplace(const bool state);
				void setReflectReplace(const bool state);
			};
		}
	}
}