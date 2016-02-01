/*==============================================================================

  Program: 3D Slicer

  Portions (c) Copyright Brigham and Women's Hospital (BWH) All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

==============================================================================*/

// Qt includes
#include <QtPlugin>

// PointCloud Logic includes
#include <vtkSlicerPointCloudLogic.h>

// PointCloud includes
#include "qSlicerPointCloudModule.h"
#include "qSlicerPointCloudModuleWidget.h"

//-----------------------------------------------------------------------------
Q_EXPORT_PLUGIN2(qSlicerPointCloudModule, qSlicerPointCloudModule);

//-----------------------------------------------------------------------------
/// \ingroup Slicer_QtModules_ExtensionTemplate
class qSlicerPointCloudModulePrivate
{
public:
  qSlicerPointCloudModulePrivate();
};

//-----------------------------------------------------------------------------
// qSlicerPointCloudModulePrivate methods

//-----------------------------------------------------------------------------
qSlicerPointCloudModulePrivate::qSlicerPointCloudModulePrivate()
{
}

//-----------------------------------------------------------------------------
// qSlicerPointCloudModule methods

//-----------------------------------------------------------------------------
qSlicerPointCloudModule::qSlicerPointCloudModule(QObject* _parent)
  : Superclass(_parent)
  , d_ptr(new qSlicerPointCloudModulePrivate)
{
}

//-----------------------------------------------------------------------------
qSlicerPointCloudModule::~qSlicerPointCloudModule()
{
}

//-----------------------------------------------------------------------------
QString qSlicerPointCloudModule::helpText() const
{
  return "This is a loadable module that can be bundled in an extension";
}

//-----------------------------------------------------------------------------
QString qSlicerPointCloudModule::acknowledgementText() const
{
  return "This work was partially funded by NIH grant NXNNXXNNNNNN-NNXN";
}

//-----------------------------------------------------------------------------
QStringList qSlicerPointCloudModule::contributors() const
{
  QStringList moduleContributors;
  moduleContributors << QString("John Doe (AnyWare Corp.)");
  return moduleContributors;
}

//-----------------------------------------------------------------------------
QIcon qSlicerPointCloudModule::icon() const
{
  return QIcon(":/Icons/PointCloud.png");
}

//-----------------------------------------------------------------------------
QStringList qSlicerPointCloudModule::categories() const
{
  return QStringList() << "Examples";
}

//-----------------------------------------------------------------------------
QStringList qSlicerPointCloudModule::dependencies() const
{
  return QStringList();
}

//-----------------------------------------------------------------------------
void qSlicerPointCloudModule::setup()
{
  this->Superclass::setup();
}

//-----------------------------------------------------------------------------
qSlicerAbstractModuleRepresentation* qSlicerPointCloudModule
::createWidgetRepresentation()
{
  return new qSlicerPointCloudModuleWidget;
}

//-----------------------------------------------------------------------------
vtkMRMLAbstractLogic* qSlicerPointCloudModule::createLogic()
{
  return vtkSlicerPointCloudLogic::New();
}
