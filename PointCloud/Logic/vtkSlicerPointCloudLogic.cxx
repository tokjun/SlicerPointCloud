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

// PointCloud Logic includes
#include "vtkSlicerPointCloudLogic.h"

// MRML includes
#include <vtkMRMLScene.h>

// VTK includes
#include <vtkIntArray.h>
#include <vtkNew.h>
#include <vtkObjectFactory.h>

#include "vtkMRMLPointCloudNode.h"
#include "vtkMRMLPointCloudDisplayNode.h"
#include "vtkMRMLPointCloudStorageNode.h"


// STD includes
#include <cassert>

//----------------------------------------------------------------------------
vtkStandardNewMacro(vtkSlicerPointCloudLogic);

//----------------------------------------------------------------------------
vtkSlicerPointCloudLogic::vtkSlicerPointCloudLogic()
{
}

//----------------------------------------------------------------------------
vtkSlicerPointCloudLogic::~vtkSlicerPointCloudLogic()
{
}

//----------------------------------------------------------------------------
void vtkSlicerPointCloudLogic::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
}

//---------------------------------------------------------------------------
void vtkSlicerPointCloudLogic::SetMRMLSceneInternal(vtkMRMLScene * newScene)
{
  vtkNew<vtkIntArray> events;
  events->InsertNextValue(vtkMRMLScene::NodeAddedEvent);
  events->InsertNextValue(vtkMRMLScene::NodeRemovedEvent);
  events->InsertNextValue(vtkMRMLScene::EndBatchProcessEvent);
  this->SetAndObserveMRMLSceneEventsInternal(newScene, events.GetPointer());
}

//-----------------------------------------------------------------------------
void vtkSlicerPointCloudLogic::RegisterNodes()
{
  assert(this->GetMRMLScene() != 0);
  vtkMRMLScene * scene = this->GetMRMLScene();
  if(!scene)
    {
    return;
    }

  scene->RegisterNodeClass(vtkNew<vtkMRMLPointCloudNode>().GetPointer());
  scene->RegisterNodeClass(vtkNew<vtkMRMLPointCloudDisplayNode>().GetPointer());
  scene->RegisterNodeClass(vtkNew<vtkMRMLPointCloudStorageNode>().GetPointer());

}

//---------------------------------------------------------------------------
void vtkSlicerPointCloudLogic::UpdateFromMRMLScene()
{
  assert(this->GetMRMLScene() != 0);
}

//---------------------------------------------------------------------------
void vtkSlicerPointCloudLogic
::OnMRMLSceneNodeAdded(vtkMRMLNode* vtkNotUsed(node))
{
}

//---------------------------------------------------------------------------
void vtkSlicerPointCloudLogic
::OnMRMLSceneNodeRemoved(vtkMRMLNode* vtkNotUsed(node))
{
}
