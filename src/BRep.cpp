#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <TopoDS_Builder.hxx>
#include <TopoDS_Face.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <TopLoc_Location.hxx>
#include <Poly_Triangulation.hxx>
#include <TopoDS_Edge.hxx>
#include <Geom_Curve.hxx>
#include <Poly_Polygon3D.hxx>
#include <Poly_PolygonOnTriangulation.hxx>
#include <Geom2d_Curve.hxx>
#include <gp_Pnt2d.hxx>
#include <Poly_Polygon2D.hxx>
#include <GeomAbs_Shape.hxx>
#include <TopoDS_Vertex.hxx>
#include <gp_Pnt.hxx>
#include <BRep_Builder.hxx>
#include <TopoDS_TFace.hxx>
#include <TopoDS_TShape.hxx>
#include <Standard_Type.hxx>
#include <BRep_TFace.hxx>
#include <Standard_Transient.hxx>
#include <BRep_PointRepresentation.hxx>
#include <NCollection_BaseList.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_List.hxx>
#include <BRep_ListOfPointRepresentation.hxx>
#include <TopoDS_TVertex.hxx>
#include <BRep_TVertex.hxx>
#include <TopoDS_Shape.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <BRep_Tool.hxx>
#include <BRep_CurveRepresentation.hxx>
#include <BRep_GCurve.hxx>
#include <BRep_Curve3D.hxx>
#include <BRep_CurveOn2Surfaces.hxx>
#include <BRep_CurveOnSurface.hxx>
#include <BRep_CurveOnClosedSurface.hxx>
#include <BRep_ListOfCurveRepresentation.hxx>
#include <BRep_PointOnCurve.hxx>
#include <BRep_PointsOnSurface.hxx>
#include <BRep_PointOnCurveOnSurface.hxx>
#include <BRep_PointOnSurface.hxx>
#include <BRep_Polygon3D.hxx>
#include <BRep_PolygonOnSurface.hxx>
#include <BRep_PolygonOnClosedSurface.hxx>
#include <BRep_PolygonOnTriangulation.hxx>
#include <BRep_PolygonOnClosedTriangulation.hxx>
#include <TopoDS_TEdge.hxx>
#include <BRep_TEdge.hxx>

PYBIND11_MODULE(BRep, mod) {

	// IMPORT
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.Geom");
	py::module::import("OCCT.TopLoc");
	py::module::import("OCCT.Poly");
	py::module::import("OCCT.Geom2d");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.GeomAbs");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.TopAbs");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRep_Builder.hxx
	py::class_<BRep_Builder, std::unique_ptr<BRep_Builder, Deleter<BRep_Builder>>, TopoDS_Builder> cls_BRep_Builder(mod, "BRep_Builder", "A framework providing advanced tolerance control. It is used to build Shapes. If tolerance control is required, you are advised to: 1. build a default precision for topology, using the classes provided in the BRepAPI package 2. update the tolerance of the resulting shape. Note that only vertices, edges and faces have meaningful tolerance control. The tolerance value must always comply with the condition that face tolerances are more restrictive than edge tolerances which are more restrictive than vertex tolerances. In other words: Tol(Vertex) >= Tol(Edge) >= Tol(Face). Other rules in setting tolerance include: - you can open up tolerance but should never restrict it - an edge cannot be included within the fusion of the tolerance spheres of two vertices");
	cls_BRep_Builder.def(py::init<>());
	cls_BRep_Builder.def("MakeFace", (void (BRep_Builder::*)(TopoDS_Face &) const ) &BRep_Builder::MakeFace, "Makes an undefined Face.", py::arg("F"));
	cls_BRep_Builder.def("MakeFace", (void (BRep_Builder::*)(TopoDS_Face &, const opencascade::handle<Geom_Surface> &, const Standard_Real) const ) &BRep_Builder::MakeFace, "Makes a Face with a surface.", py::arg("F"), py::arg("S"), py::arg("Tol"));
	cls_BRep_Builder.def("MakeFace", (void (BRep_Builder::*)(TopoDS_Face &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const Standard_Real) const ) &BRep_Builder::MakeFace, "Makes a Face with a surface and a location.", py::arg("F"), py::arg("S"), py::arg("L"), py::arg("Tol"));
	cls_BRep_Builder.def("MakeFace", (void (BRep_Builder::*)(TopoDS_Face &, const opencascade::handle<Poly_Triangulation> &) const ) &BRep_Builder::MakeFace, "Makes a Face with a triangulation. The triangulation is in the same reference system than the TFace.", py::arg("F"), py::arg("T"));
	cls_BRep_Builder.def("UpdateFace", (void (BRep_Builder::*)(const TopoDS_Face &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const Standard_Real) const ) &BRep_Builder::UpdateFace, "Updates the face F using the tolerance value Tol, surface S and location Location.", py::arg("F"), py::arg("S"), py::arg("L"), py::arg("Tol"));
	cls_BRep_Builder.def("UpdateFace", (void (BRep_Builder::*)(const TopoDS_Face &, const opencascade::handle<Poly_Triangulation> &) const ) &BRep_Builder::UpdateFace, "Changes a face triangulation.", py::arg("F"), py::arg("T"));
	cls_BRep_Builder.def("UpdateFace", (void (BRep_Builder::*)(const TopoDS_Face &, const Standard_Real) const ) &BRep_Builder::UpdateFace, "Updates the face Tolerance.", py::arg("F"), py::arg("Tol"));
	cls_BRep_Builder.def("NaturalRestriction", (void (BRep_Builder::*)(const TopoDS_Face &, const Standard_Boolean) const ) &BRep_Builder::NaturalRestriction, "Sets the NaturalRestriction flag of the face.", py::arg("F"), py::arg("N"));
	cls_BRep_Builder.def("MakeEdge", (void (BRep_Builder::*)(TopoDS_Edge &) const ) &BRep_Builder::MakeEdge, "Makes an undefined Edge (no geometry).", py::arg("E"));
	cls_BRep_Builder.def("MakeEdge", (void (BRep_Builder::*)(TopoDS_Edge &, const opencascade::handle<Geom_Curve> &, const Standard_Real) const ) &BRep_Builder::MakeEdge, "Makes an Edge with a curve.", py::arg("E"), py::arg("C"), py::arg("Tol"));
	cls_BRep_Builder.def("MakeEdge", (void (BRep_Builder::*)(TopoDS_Edge &, const opencascade::handle<Geom_Curve> &, const TopLoc_Location &, const Standard_Real) const ) &BRep_Builder::MakeEdge, "Makes an Edge with a curve and a location.", py::arg("E"), py::arg("C"), py::arg("L"), py::arg("Tol"));
	cls_BRep_Builder.def("MakeEdge", (void (BRep_Builder::*)(TopoDS_Edge &, const opencascade::handle<Poly_Polygon3D> &) const ) &BRep_Builder::MakeEdge, "Makes an Edge with a polygon 3d.", py::arg("E"), py::arg("P"));
	cls_BRep_Builder.def("MakeEdge", (void (BRep_Builder::*)(TopoDS_Edge &, const opencascade::handle<Poly_PolygonOnTriangulation> &, const opencascade::handle<Poly_Triangulation> &) const ) &BRep_Builder::MakeEdge, "makes an Edge polygon on Triangulation.", py::arg("E"), py::arg("N"), py::arg("T"));
	cls_BRep_Builder.def("MakeEdge", (void (BRep_Builder::*)(TopoDS_Edge &, const opencascade::handle<Poly_PolygonOnTriangulation> &, const opencascade::handle<Poly_Triangulation> &, const TopLoc_Location &) const ) &BRep_Builder::MakeEdge, "makes an Edge polygon on Triangulation.", py::arg("E"), py::arg("N"), py::arg("T"), py::arg("L"));
	cls_BRep_Builder.def("UpdateEdge", (void (BRep_Builder::*)(const TopoDS_Edge &, const opencascade::handle<Geom_Curve> &, const Standard_Real) const ) &BRep_Builder::UpdateEdge, "Sets a 3D curve for the edge. If <C> is a null handle, remove any existing 3d curve.", py::arg("E"), py::arg("C"), py::arg("Tol"));
	cls_BRep_Builder.def("UpdateEdge", (void (BRep_Builder::*)(const TopoDS_Edge &, const opencascade::handle<Geom_Curve> &, const TopLoc_Location &, const Standard_Real) const ) &BRep_Builder::UpdateEdge, "Sets a 3D curve for the edge. If <C> is a null handle, remove any existing 3d curve.", py::arg("E"), py::arg("C"), py::arg("L"), py::arg("Tol"));
	cls_BRep_Builder.def("UpdateEdge", (void (BRep_Builder::*)(const TopoDS_Edge &, const opencascade::handle<Geom2d_Curve> &, const TopoDS_Face &, const Standard_Real) const ) &BRep_Builder::UpdateEdge, "Sets a pcurve for the edge on the face. If <C> is a null handle, remove any existing pcurve.", py::arg("E"), py::arg("C"), py::arg("F"), py::arg("Tol"));
	cls_BRep_Builder.def("UpdateEdge", (void (BRep_Builder::*)(const TopoDS_Edge &, const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const TopoDS_Face &, const Standard_Real) const ) &BRep_Builder::UpdateEdge, "Sets pcurves for the edge on the closed face. If <C1> or <C2> is a null handle, remove any existing pcurve.", py::arg("E"), py::arg("C1"), py::arg("C2"), py::arg("F"), py::arg("Tol"));
	cls_BRep_Builder.def("UpdateEdge", (void (BRep_Builder::*)(const TopoDS_Edge &, const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const Standard_Real) const ) &BRep_Builder::UpdateEdge, "Sets a pcurve for the edge on the face. If <C> is a null handle, remove any existing pcurve.", py::arg("E"), py::arg("C"), py::arg("S"), py::arg("L"), py::arg("Tol"));
	cls_BRep_Builder.def("UpdateEdge", (void (BRep_Builder::*)(const TopoDS_Edge &, const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const Standard_Real, const gp_Pnt2d &, const gp_Pnt2d &) const ) &BRep_Builder::UpdateEdge, "Sets a pcurve for the edge on the face. If <C> is a null handle, remove any existing pcurve. Sets UV bounds for curve repsentation", py::arg("E"), py::arg("C"), py::arg("S"), py::arg("L"), py::arg("Tol"), py::arg("Pf"), py::arg("Pl"));
	cls_BRep_Builder.def("UpdateEdge", (void (BRep_Builder::*)(const TopoDS_Edge &, const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const Standard_Real) const ) &BRep_Builder::UpdateEdge, "Sets pcurves for the edge on the closed surface. <C1> or <C2> is a null handle, remove any existing pcurve.", py::arg("E"), py::arg("C1"), py::arg("C2"), py::arg("S"), py::arg("L"), py::arg("Tol"));
	cls_BRep_Builder.def("UpdateEdge", (void (BRep_Builder::*)(const TopoDS_Edge &, const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const Standard_Real, const gp_Pnt2d &, const gp_Pnt2d &) const ) &BRep_Builder::UpdateEdge, "Sets pcurves for the edge on the closed surface. <C1> or <C2> is a null handle, remove any existing pcurve. Sets UV bounds for curve repsentation", py::arg("E"), py::arg("C1"), py::arg("C2"), py::arg("S"), py::arg("L"), py::arg("Tol"), py::arg("Pf"), py::arg("Pl"));
	cls_BRep_Builder.def("UpdateEdge", (void (BRep_Builder::*)(const TopoDS_Edge &, const opencascade::handle<Poly_Polygon3D> &) const ) &BRep_Builder::UpdateEdge, "Changes an Edge 3D polygon. A null Polygon removes the 3d Polygon.", py::arg("E"), py::arg("P"));
	cls_BRep_Builder.def("UpdateEdge", (void (BRep_Builder::*)(const TopoDS_Edge &, const opencascade::handle<Poly_Polygon3D> &, const TopLoc_Location &) const ) &BRep_Builder::UpdateEdge, "Changes an Edge 3D polygon. A null Polygon removes the 3d Polygon.", py::arg("E"), py::arg("P"), py::arg("L"));
	cls_BRep_Builder.def("UpdateEdge", (void (BRep_Builder::*)(const TopoDS_Edge &, const opencascade::handle<Poly_PolygonOnTriangulation> &, const opencascade::handle<Poly_Triangulation> &) const ) &BRep_Builder::UpdateEdge, "Changes an Edge polygon on Triangulation.", py::arg("E"), py::arg("N"), py::arg("T"));
	cls_BRep_Builder.def("UpdateEdge", (void (BRep_Builder::*)(const TopoDS_Edge &, const opencascade::handle<Poly_PolygonOnTriangulation> &, const opencascade::handle<Poly_Triangulation> &, const TopLoc_Location &) const ) &BRep_Builder::UpdateEdge, "Changes an Edge polygon on Triangulation.", py::arg("E"), py::arg("N"), py::arg("T"), py::arg("L"));
	cls_BRep_Builder.def("UpdateEdge", (void (BRep_Builder::*)(const TopoDS_Edge &, const opencascade::handle<Poly_PolygonOnTriangulation> &, const opencascade::handle<Poly_PolygonOnTriangulation> &, const opencascade::handle<Poly_Triangulation> &) const ) &BRep_Builder::UpdateEdge, "Changes an Edge polygon on Triangulation.", py::arg("E"), py::arg("N1"), py::arg("N2"), py::arg("T"));
	cls_BRep_Builder.def("UpdateEdge", (void (BRep_Builder::*)(const TopoDS_Edge &, const opencascade::handle<Poly_PolygonOnTriangulation> &, const opencascade::handle<Poly_PolygonOnTriangulation> &, const opencascade::handle<Poly_Triangulation> &, const TopLoc_Location &) const ) &BRep_Builder::UpdateEdge, "Changes an Edge polygon on Triangulation.", py::arg("E"), py::arg("N1"), py::arg("N2"), py::arg("T"), py::arg("L"));
	cls_BRep_Builder.def("UpdateEdge", (void (BRep_Builder::*)(const TopoDS_Edge &, const opencascade::handle<Poly_Polygon2D> &, const TopoDS_Face &) const ) &BRep_Builder::UpdateEdge, "Changes Edge polygon on a face.", py::arg("E"), py::arg("P"), py::arg("S"));
	cls_BRep_Builder.def("UpdateEdge", (void (BRep_Builder::*)(const TopoDS_Edge &, const opencascade::handle<Poly_Polygon2D> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &) const ) &BRep_Builder::UpdateEdge, "Changes Edge polygon on a face.", py::arg("E"), py::arg("P"), py::arg("S"), py::arg("T"));
	cls_BRep_Builder.def("UpdateEdge", (void (BRep_Builder::*)(const TopoDS_Edge &, const opencascade::handle<Poly_Polygon2D> &, const opencascade::handle<Poly_Polygon2D> &, const TopoDS_Face &) const ) &BRep_Builder::UpdateEdge, "Changes Edge polygons on a face.", py::arg("E"), py::arg("P1"), py::arg("P2"), py::arg("S"));
	cls_BRep_Builder.def("UpdateEdge", (void (BRep_Builder::*)(const TopoDS_Edge &, const opencascade::handle<Poly_Polygon2D> &, const opencascade::handle<Poly_Polygon2D> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &) const ) &BRep_Builder::UpdateEdge, "Changes Edge polygons on a face.", py::arg("E"), py::arg("P1"), py::arg("P2"), py::arg("S"), py::arg("L"));
	cls_BRep_Builder.def("UpdateEdge", (void (BRep_Builder::*)(const TopoDS_Edge &, const Standard_Real) const ) &BRep_Builder::UpdateEdge, "Updates the edge tolerance.", py::arg("E"), py::arg("Tol"));
	cls_BRep_Builder.def("Continuity", (void (BRep_Builder::*)(const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &, const GeomAbs_Shape) const ) &BRep_Builder::Continuity, "Sets the geometric continuity on the edge.", py::arg("E"), py::arg("F1"), py::arg("F2"), py::arg("C"));
	cls_BRep_Builder.def("Continuity", (void (BRep_Builder::*)(const TopoDS_Edge &, const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const TopLoc_Location &, const GeomAbs_Shape) const ) &BRep_Builder::Continuity, "Sets the geometric continuity on the edge.", py::arg("E"), py::arg("S1"), py::arg("S2"), py::arg("L1"), py::arg("L2"), py::arg("C"));
	cls_BRep_Builder.def("SameParameter", (void (BRep_Builder::*)(const TopoDS_Edge &, const Standard_Boolean) const ) &BRep_Builder::SameParameter, "Sets the same parameter flag for the edge <E>.", py::arg("E"), py::arg("S"));
	cls_BRep_Builder.def("SameRange", (void (BRep_Builder::*)(const TopoDS_Edge &, const Standard_Boolean) const ) &BRep_Builder::SameRange, "Sets the same range flag for the edge <E>.", py::arg("E"), py::arg("S"));
	cls_BRep_Builder.def("Degenerated", (void (BRep_Builder::*)(const TopoDS_Edge &, const Standard_Boolean) const ) &BRep_Builder::Degenerated, "Sets the degenerated flag for the edge <E>.", py::arg("E"), py::arg("D"));
	cls_BRep_Builder.def("Range", [](BRep_Builder &self, const TopoDS_Edge & a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.Range(a0, a1, a2); }, py::arg("E"), py::arg("First"), py::arg("Last"));
	cls_BRep_Builder.def("Range", (void (BRep_Builder::*)(const TopoDS_Edge &, const Standard_Real, const Standard_Real, const Standard_Boolean) const ) &BRep_Builder::Range, "Sets the range of the 3d curve if Only3d=TRUE, otherwise sets the range to all the representations", py::arg("E"), py::arg("First"), py::arg("Last"), py::arg("Only3d"));
	cls_BRep_Builder.def("Range", (void (BRep_Builder::*)(const TopoDS_Edge &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const Standard_Real, const Standard_Real) const ) &BRep_Builder::Range, "Sets the range of the edge on the pcurve on the surface.", py::arg("E"), py::arg("S"), py::arg("L"), py::arg("First"), py::arg("Last"));
	cls_BRep_Builder.def("Range", (void (BRep_Builder::*)(const TopoDS_Edge &, const TopoDS_Face &, const Standard_Real, const Standard_Real) const ) &BRep_Builder::Range, "Sets the range of the edge on the pcurve on the face.", py::arg("E"), py::arg("F"), py::arg("First"), py::arg("Last"));
	cls_BRep_Builder.def("Transfert", (void (BRep_Builder::*)(const TopoDS_Edge &, const TopoDS_Edge &) const ) &BRep_Builder::Transfert, "Add to <Eout> the geometric representations of <Ein>.", py::arg("Ein"), py::arg("Eout"));
	cls_BRep_Builder.def("MakeVertex", (void (BRep_Builder::*)(TopoDS_Vertex &) const ) &BRep_Builder::MakeVertex, "Makes an udefined vertex without geometry.", py::arg("V"));
	cls_BRep_Builder.def("MakeVertex", (void (BRep_Builder::*)(TopoDS_Vertex &, const gp_Pnt &, const Standard_Real) const ) &BRep_Builder::MakeVertex, "Makes a vertex from a 3D point.", py::arg("V"), py::arg("P"), py::arg("Tol"));
	cls_BRep_Builder.def("UpdateVertex", (void (BRep_Builder::*)(const TopoDS_Vertex &, const gp_Pnt &, const Standard_Real) const ) &BRep_Builder::UpdateVertex, "Sets a 3D point on the vertex.", py::arg("V"), py::arg("P"), py::arg("Tol"));
	cls_BRep_Builder.def("UpdateVertex", (void (BRep_Builder::*)(const TopoDS_Vertex &, const Standard_Real, const TopoDS_Edge &, const Standard_Real) const ) &BRep_Builder::UpdateVertex, "Sets the parameter for the vertex on the edge curves.", py::arg("V"), py::arg("P"), py::arg("E"), py::arg("Tol"));
	cls_BRep_Builder.def("UpdateVertex", (void (BRep_Builder::*)(const TopoDS_Vertex &, const Standard_Real, const TopoDS_Edge &, const TopoDS_Face &, const Standard_Real) const ) &BRep_Builder::UpdateVertex, "Sets the parameter for the vertex on the edge pcurve on the face.", py::arg("V"), py::arg("P"), py::arg("E"), py::arg("F"), py::arg("Tol"));
	cls_BRep_Builder.def("UpdateVertex", (void (BRep_Builder::*)(const TopoDS_Vertex &, const Standard_Real, const TopoDS_Edge &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const Standard_Real) const ) &BRep_Builder::UpdateVertex, "Sets the parameter for the vertex on the edge pcurve on the surface.", py::arg("V"), py::arg("P"), py::arg("E"), py::arg("S"), py::arg("L"), py::arg("Tol"));
	cls_BRep_Builder.def("UpdateVertex", (void (BRep_Builder::*)(const TopoDS_Vertex &, const Standard_Real, const Standard_Real, const TopoDS_Face &, const Standard_Real) const ) &BRep_Builder::UpdateVertex, "Sets the parameters for the vertex on the face.", py::arg("Ve"), py::arg("U"), py::arg("V"), py::arg("F"), py::arg("Tol"));
	cls_BRep_Builder.def("UpdateVertex", (void (BRep_Builder::*)(const TopoDS_Vertex &, const Standard_Real) const ) &BRep_Builder::UpdateVertex, "Updates the vertex tolerance.", py::arg("V"), py::arg("Tol"));
	cls_BRep_Builder.def("Transfert", (void (BRep_Builder::*)(const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Vertex &, const TopoDS_Vertex &) const ) &BRep_Builder::Transfert, "Transfert the parameters of Vin on Ein as the parameter of Vout on Eout.", py::arg("Ein"), py::arg("Eout"), py::arg("Vin"), py::arg("Vout"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRep_TFace.hxx
	py::class_<BRep_TFace, opencascade::handle<BRep_TFace>, TopoDS_TFace> cls_BRep_TFace(mod, "BRep_TFace", "The Tface from BRep is based on the TFace from TopoDS. The TFace contains :");
	cls_BRep_TFace.def(py::init<>());
	cls_BRep_TFace.def("Surface", (const opencascade::handle<Geom_Surface> & (BRep_TFace::*)() const ) &BRep_TFace::Surface, "None");
	cls_BRep_TFace.def("Triangulation", (const opencascade::handle<Poly_Triangulation> & (BRep_TFace::*)() const ) &BRep_TFace::Triangulation, "None");
	cls_BRep_TFace.def("Location", (const TopLoc_Location & (BRep_TFace::*)() const ) &BRep_TFace::Location, "None");
	cls_BRep_TFace.def("Tolerance", (Standard_Real (BRep_TFace::*)() const ) &BRep_TFace::Tolerance, "None");
	cls_BRep_TFace.def("Surface", (void (BRep_TFace::*)(const opencascade::handle<Geom_Surface> &)) &BRep_TFace::Surface, "None", py::arg("S"));
	cls_BRep_TFace.def("Triangulation", (void (BRep_TFace::*)(const opencascade::handle<Poly_Triangulation> &)) &BRep_TFace::Triangulation, "None", py::arg("T"));
	cls_BRep_TFace.def("Location", (void (BRep_TFace::*)(const TopLoc_Location &)) &BRep_TFace::Location, "None", py::arg("L"));
	cls_BRep_TFace.def("Tolerance", (void (BRep_TFace::*)(const Standard_Real)) &BRep_TFace::Tolerance, "None", py::arg("T"));
	cls_BRep_TFace.def("NaturalRestriction", (Standard_Boolean (BRep_TFace::*)() const ) &BRep_TFace::NaturalRestriction, "None");
	cls_BRep_TFace.def("NaturalRestriction", (void (BRep_TFace::*)(const Standard_Boolean)) &BRep_TFace::NaturalRestriction, "None", py::arg("N"));
	cls_BRep_TFace.def("EmptyCopy", (opencascade::handle<TopoDS_TShape> (BRep_TFace::*)() const ) &BRep_TFace::EmptyCopy, "Returns a copy of the TShape with no sub-shapes. The new Face has no triangulation.");
	cls_BRep_TFace.def_static("get_type_name_", (const char * (*)()) &BRep_TFace::get_type_name, "None");
	cls_BRep_TFace.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRep_TFace::get_type_descriptor, "None");
	cls_BRep_TFace.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRep_TFace::*)() const ) &BRep_TFace::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRep_PointRepresentation.hxx
	py::class_<BRep_PointRepresentation, opencascade::handle<BRep_PointRepresentation>, Standard_Transient> cls_BRep_PointRepresentation(mod, "BRep_PointRepresentation", "Root class for the points representations. Contains a location and a parameter.");
	cls_BRep_PointRepresentation.def("IsPointOnCurve", (Standard_Boolean (BRep_PointRepresentation::*)() const ) &BRep_PointRepresentation::IsPointOnCurve, "A point on a 3d curve.");
	cls_BRep_PointRepresentation.def("IsPointOnCurveOnSurface", (Standard_Boolean (BRep_PointRepresentation::*)() const ) &BRep_PointRepresentation::IsPointOnCurveOnSurface, "A point on a 2d curve on a surface.");
	cls_BRep_PointRepresentation.def("IsPointOnSurface", (Standard_Boolean (BRep_PointRepresentation::*)() const ) &BRep_PointRepresentation::IsPointOnSurface, "A point on a surface.");
	cls_BRep_PointRepresentation.def("IsPointOnCurve", (Standard_Boolean (BRep_PointRepresentation::*)(const opencascade::handle<Geom_Curve> &, const TopLoc_Location &) const ) &BRep_PointRepresentation::IsPointOnCurve, "A point on the curve <C>.", py::arg("C"), py::arg("L"));
	cls_BRep_PointRepresentation.def("IsPointOnCurveOnSurface", (Standard_Boolean (BRep_PointRepresentation::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &) const ) &BRep_PointRepresentation::IsPointOnCurveOnSurface, "A point on the 2d curve <PC> on the surface <S>.", py::arg("PC"), py::arg("S"), py::arg("L"));
	cls_BRep_PointRepresentation.def("IsPointOnSurface", (Standard_Boolean (BRep_PointRepresentation::*)(const opencascade::handle<Geom_Surface> &, const TopLoc_Location &) const ) &BRep_PointRepresentation::IsPointOnSurface, "A point on the surface <S>.", py::arg("S"), py::arg("L"));
	cls_BRep_PointRepresentation.def("Location", (const TopLoc_Location & (BRep_PointRepresentation::*)() const ) &BRep_PointRepresentation::Location, "None");
	cls_BRep_PointRepresentation.def("Location", (void (BRep_PointRepresentation::*)(const TopLoc_Location &)) &BRep_PointRepresentation::Location, "None", py::arg("L"));
	cls_BRep_PointRepresentation.def("Parameter", (Standard_Real (BRep_PointRepresentation::*)() const ) &BRep_PointRepresentation::Parameter, "None");
	cls_BRep_PointRepresentation.def("Parameter", (void (BRep_PointRepresentation::*)(const Standard_Real)) &BRep_PointRepresentation::Parameter, "None", py::arg("P"));
	cls_BRep_PointRepresentation.def("Parameter2", (Standard_Real (BRep_PointRepresentation::*)() const ) &BRep_PointRepresentation::Parameter2, "None");
	cls_BRep_PointRepresentation.def("Parameter2", (void (BRep_PointRepresentation::*)(const Standard_Real)) &BRep_PointRepresentation::Parameter2, "None", py::arg("P"));
	cls_BRep_PointRepresentation.def("Curve", (const opencascade::handle<Geom_Curve> & (BRep_PointRepresentation::*)() const ) &BRep_PointRepresentation::Curve, "None");
	cls_BRep_PointRepresentation.def("Curve", (void (BRep_PointRepresentation::*)(const opencascade::handle<Geom_Curve> &)) &BRep_PointRepresentation::Curve, "None", py::arg("C"));
	cls_BRep_PointRepresentation.def("PCurve", (const opencascade::handle<Geom2d_Curve> & (BRep_PointRepresentation::*)() const ) &BRep_PointRepresentation::PCurve, "None");
	cls_BRep_PointRepresentation.def("PCurve", (void (BRep_PointRepresentation::*)(const opencascade::handle<Geom2d_Curve> &)) &BRep_PointRepresentation::PCurve, "None", py::arg("C"));
	cls_BRep_PointRepresentation.def("Surface", (const opencascade::handle<Geom_Surface> & (BRep_PointRepresentation::*)() const ) &BRep_PointRepresentation::Surface, "None");
	cls_BRep_PointRepresentation.def("Surface", (void (BRep_PointRepresentation::*)(const opencascade::handle<Geom_Surface> &)) &BRep_PointRepresentation::Surface, "None", py::arg("S"));
	cls_BRep_PointRepresentation.def_static("get_type_name_", (const char * (*)()) &BRep_PointRepresentation::get_type_name, "None");
	cls_BRep_PointRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRep_PointRepresentation::get_type_descriptor, "None");
	cls_BRep_PointRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRep_PointRepresentation::*)() const ) &BRep_PointRepresentation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRep_TVertex.hxx
	py::class_<BRep_TVertex, opencascade::handle<BRep_TVertex>, TopoDS_TVertex> cls_BRep_TVertex(mod, "BRep_TVertex", "The TVertex from BRep inherits from the TVertex from TopoDS. It contains the geometric data.");
	cls_BRep_TVertex.def(py::init<>());
	cls_BRep_TVertex.def("Tolerance", (Standard_Real (BRep_TVertex::*)() const ) &BRep_TVertex::Tolerance, "None");
	cls_BRep_TVertex.def("Tolerance", (void (BRep_TVertex::*)(const Standard_Real)) &BRep_TVertex::Tolerance, "None", py::arg("T"));
	cls_BRep_TVertex.def("UpdateTolerance", (void (BRep_TVertex::*)(const Standard_Real)) &BRep_TVertex::UpdateTolerance, "Sets the tolerance to the max of <T> and the current tolerance.", py::arg("T"));
	cls_BRep_TVertex.def("Pnt", (const gp_Pnt & (BRep_TVertex::*)() const ) &BRep_TVertex::Pnt, "None");
	cls_BRep_TVertex.def("Pnt", (void (BRep_TVertex::*)(const gp_Pnt &)) &BRep_TVertex::Pnt, "None", py::arg("P"));
	cls_BRep_TVertex.def("Points", (const BRep_ListOfPointRepresentation & (BRep_TVertex::*)() const ) &BRep_TVertex::Points, "None");
	cls_BRep_TVertex.def("ChangePoints", (BRep_ListOfPointRepresentation & (BRep_TVertex::*)()) &BRep_TVertex::ChangePoints, "None");
	cls_BRep_TVertex.def("EmptyCopy", (opencascade::handle<TopoDS_TShape> (BRep_TVertex::*)() const ) &BRep_TVertex::EmptyCopy, "Returns a copy of the TShape with no sub-shapes.");
	cls_BRep_TVertex.def_static("get_type_name_", (const char * (*)()) &BRep_TVertex::get_type_name, "None");
	cls_BRep_TVertex.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRep_TVertex::get_type_descriptor, "None");
	cls_BRep_TVertex.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRep_TVertex::*)() const ) &BRep_TVertex::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRep_Tool.hxx
	py::class_<BRep_Tool, std::unique_ptr<BRep_Tool, Deleter<BRep_Tool>>> cls_BRep_Tool(mod, "BRep_Tool", "Provides class methods to access to the geometry of BRep shapes.");
	cls_BRep_Tool.def(py::init<>());
	cls_BRep_Tool.def_static("IsClosed_", (Standard_Boolean (*)(const TopoDS_Shape &)) &BRep_Tool::IsClosed, "If S is Shell, returns True if it has no free boundaries (edges). If S is Wire, returns True if it has no free ends (vertices). (Internal and External sub-shepes are ignored in these checks) If S is Edge, returns True if its vertices are the same. For other shape types returns S.Closed().", py::arg("S"));
	cls_BRep_Tool.def_static("Surface_", (const opencascade::handle<Geom_Surface> & (*)(const TopoDS_Face &, TopLoc_Location &)) &BRep_Tool::Surface, "Returns the geometric surface of the face. Returns in <L> the location for the surface.", py::arg("F"), py::arg("L"));
	cls_BRep_Tool.def_static("Surface_", (opencascade::handle<Geom_Surface> (*)(const TopoDS_Face &)) &BRep_Tool::Surface, "Returns the geometric surface of the face. It can be a copy if there is a Location.", py::arg("F"));
	cls_BRep_Tool.def_static("Triangulation_", (const opencascade::handle<Poly_Triangulation> & (*)(const TopoDS_Face &, TopLoc_Location &)) &BRep_Tool::Triangulation, "Returns the Triangulation of the face. It is a null handle if there is no triangulation.", py::arg("F"), py::arg("L"));
	cls_BRep_Tool.def_static("Tolerance_", (Standard_Real (*)(const TopoDS_Face &)) &BRep_Tool::Tolerance, "Returns the tolerance of the face.", py::arg("F"));
	cls_BRep_Tool.def_static("NaturalRestriction_", (Standard_Boolean (*)(const TopoDS_Face &)) &BRep_Tool::NaturalRestriction, "Returns the NaturalRestriction flag of the face.", py::arg("F"));
	cls_BRep_Tool.def_static("IsGeometric_", (Standard_Boolean (*)(const TopoDS_Edge &)) &BRep_Tool::IsGeometric, "Returns True if <E> is a 3d curve or a curve on surface.", py::arg("E"));
	cls_BRep_Tool.def_static("Curve_", (const opencascade::handle<Geom_Curve> & (*)(const TopoDS_Edge &, TopLoc_Location &, Standard_Real &, Standard_Real &)) &BRep_Tool::Curve, "Returns the 3D curve of the edge. May be a Null handle. Returns in <L> the location for the curve. In <First> and <Last> the parameter range.", py::arg("E"), py::arg("L"), py::arg("First"), py::arg("Last"));
	cls_BRep_Tool.def_static("Curve_", (opencascade::handle<Geom_Curve> (*)(const TopoDS_Edge &, Standard_Real &, Standard_Real &)) &BRep_Tool::Curve, "Returns the 3D curve of the edge. May be a Null handle. In <First> and <Last> the parameter range. It can be a copy if there is a Location.", py::arg("E"), py::arg("First"), py::arg("Last"));
	cls_BRep_Tool.def_static("Polygon3D_", (const opencascade::handle<Poly_Polygon3D> & (*)(const TopoDS_Edge &, TopLoc_Location &)) &BRep_Tool::Polygon3D, "Returns the 3D polygon of the edge. May be a Null handle. Returns in <L> the location for the polygon.", py::arg("E"), py::arg("L"));
	cls_BRep_Tool.def_static("CurveOnSurface_", (opencascade::handle<Geom2d_Curve> (*)(const TopoDS_Edge &, const TopoDS_Face &, Standard_Real &, Standard_Real &)) &BRep_Tool::CurveOnSurface, "Returns the curve associated to the edge in the parametric space of the face. Returns a NULL handle if this curve does not exist. Returns in <First> and <Last> the parameter range.", py::arg("E"), py::arg("F"), py::arg("First"), py::arg("Last"));
	cls_BRep_Tool.def_static("CurveOnSurface_", (opencascade::handle<Geom2d_Curve> (*)(const TopoDS_Edge &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, Standard_Real &, Standard_Real &)) &BRep_Tool::CurveOnSurface, "Returns the curve associated to the edge in the parametric space of the surface. Returns a NULL handle if this curve does not exist. Returns in <First> and <Last> the parameter range.", py::arg("E"), py::arg("S"), py::arg("L"), py::arg("First"), py::arg("Last"));
	cls_BRep_Tool.def_static("CurveOnPlane_", (opencascade::handle<Geom2d_Curve> (*)(const TopoDS_Edge &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, Standard_Real &, Standard_Real &)) &BRep_Tool::CurveOnPlane, "For the planar surface builds the 2d curve for the edge by projection of the edge on plane. Returns a NULL handle if the surface is not planar or the projection failed.", py::arg("E"), py::arg("S"), py::arg("L"), py::arg("First"), py::arg("Last"));
	cls_BRep_Tool.def_static("CurveOnSurface_", (void (*)(const TopoDS_Edge &, opencascade::handle<Geom2d_Curve> &, opencascade::handle<Geom_Surface> &, TopLoc_Location &, Standard_Real &, Standard_Real &)) &BRep_Tool::CurveOnSurface, "Returns in <C>, <S>, <L> a 2d curve, a surface and a location for the edge <E>. <C> and <S> are null if the edge has no curve on surface. Returns in <First> and <Last> the parameter range.", py::arg("E"), py::arg("C"), py::arg("S"), py::arg("L"), py::arg("First"), py::arg("Last"));
	cls_BRep_Tool.def_static("CurveOnSurface_", (void (*)(const TopoDS_Edge &, opencascade::handle<Geom2d_Curve> &, opencascade::handle<Geom_Surface> &, TopLoc_Location &, Standard_Real &, Standard_Real &, const Standard_Integer)) &BRep_Tool::CurveOnSurface, "Returns in <C>, <S>, <L> the 2d curve, the surface and the location for the edge <E> of rank <Index>. <C> and <S> are null if the index is out of range. Returns in <First> and <Last> the parameter range.", py::arg("E"), py::arg("C"), py::arg("S"), py::arg("L"), py::arg("First"), py::arg("Last"), py::arg("Index"));
	cls_BRep_Tool.def_static("PolygonOnSurface_", (opencascade::handle<Poly_Polygon2D> (*)(const TopoDS_Edge &, const TopoDS_Face &)) &BRep_Tool::PolygonOnSurface, "Returns the polygon associated to the edge in the parametric space of the face. Returns a NULL handle if this polygon does not exist.", py::arg("E"), py::arg("F"));
	cls_BRep_Tool.def_static("PolygonOnSurface_", (opencascade::handle<Poly_Polygon2D> (*)(const TopoDS_Edge &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &)) &BRep_Tool::PolygonOnSurface, "Returns the polygon associated to the edge in the parametric space of the surface. Returns a NULL handle if this polygon does not exist.", py::arg("E"), py::arg("S"), py::arg("L"));
	cls_BRep_Tool.def_static("PolygonOnSurface_", (void (*)(const TopoDS_Edge &, opencascade::handle<Poly_Polygon2D> &, opencascade::handle<Geom_Surface> &, TopLoc_Location &)) &BRep_Tool::PolygonOnSurface, "Returns in <C>, <S>, <L> a 2d curve, a surface and a location for the edge <E>. <C> and <S> are null if the edge has no polygon on surface.", py::arg("E"), py::arg("C"), py::arg("S"), py::arg("L"));
	cls_BRep_Tool.def_static("PolygonOnSurface_", (void (*)(const TopoDS_Edge &, opencascade::handle<Poly_Polygon2D> &, opencascade::handle<Geom_Surface> &, TopLoc_Location &, const Standard_Integer)) &BRep_Tool::PolygonOnSurface, "Returns in <C>, <S>, <L> the 2d curve, the surface and the location for the edge <E> of rank <Index>. <C> and <S> are null if the index is out of range.", py::arg("E"), py::arg("C"), py::arg("S"), py::arg("L"), py::arg("Index"));
	cls_BRep_Tool.def_static("PolygonOnTriangulation_", (const opencascade::handle<Poly_PolygonOnTriangulation> & (*)(const TopoDS_Edge &, const opencascade::handle<Poly_Triangulation> &, const TopLoc_Location &)) &BRep_Tool::PolygonOnTriangulation, "Returns the polygon associated to the edge in the parametric space of the face. Returns a NULL handle if this polygon does not exist.", py::arg("E"), py::arg("T"), py::arg("L"));
	cls_BRep_Tool.def_static("PolygonOnTriangulation_", (void (*)(const TopoDS_Edge &, opencascade::handle<Poly_PolygonOnTriangulation> &, opencascade::handle<Poly_Triangulation> &, TopLoc_Location &)) &BRep_Tool::PolygonOnTriangulation, "Returns in <P>, <T>, <L> a polygon on triangulation, a triangulation and a location for the edge <E>. <P> and <T> are null if the edge has no polygon on triangulation.", py::arg("E"), py::arg("P"), py::arg("T"), py::arg("L"));
	cls_BRep_Tool.def_static("PolygonOnTriangulation_", (void (*)(const TopoDS_Edge &, opencascade::handle<Poly_PolygonOnTriangulation> &, opencascade::handle<Poly_Triangulation> &, TopLoc_Location &, const Standard_Integer)) &BRep_Tool::PolygonOnTriangulation, "Returns in <P>, <T>, <L> a polygon on triangulation, a triangulation and a location for the edge <E> for the range index. <C> and <S> are null if the edge has no polygon on triangulation.", py::arg("E"), py::arg("P"), py::arg("T"), py::arg("L"), py::arg("Index"));
	cls_BRep_Tool.def_static("IsClosed_", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Face &)) &BRep_Tool::IsClosed, "Returns True if <E> has two PCurves in the parametric space of <F>. i.e. <F> is on a closed surface and <E> is on the closing curve.", py::arg("E"), py::arg("F"));
	cls_BRep_Tool.def_static("IsClosed_", (Standard_Boolean (*)(const TopoDS_Edge &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &)) &BRep_Tool::IsClosed, "Returns True if <E> has two PCurves in the parametric space of <S>. i.e. <S> is a closed surface and <E> is on the closing curve.", py::arg("E"), py::arg("S"), py::arg("L"));
	cls_BRep_Tool.def_static("IsClosed_", (Standard_Boolean (*)(const TopoDS_Edge &, const opencascade::handle<Poly_Triangulation> &, const TopLoc_Location &)) &BRep_Tool::IsClosed, "Returns True if <E> has two arrays of indices in the triangulation <T>.", py::arg("E"), py::arg("T"), py::arg("L"));
	cls_BRep_Tool.def_static("Tolerance_", (Standard_Real (*)(const TopoDS_Edge &)) &BRep_Tool::Tolerance, "Returns the tolerance for <E>.", py::arg("E"));
	cls_BRep_Tool.def_static("SameParameter_", (Standard_Boolean (*)(const TopoDS_Edge &)) &BRep_Tool::SameParameter, "Returns the SameParameter flag for the edge.", py::arg("E"));
	cls_BRep_Tool.def_static("SameRange_", (Standard_Boolean (*)(const TopoDS_Edge &)) &BRep_Tool::SameRange, "Returns the SameRange flag for the edge.", py::arg("E"));
	cls_BRep_Tool.def_static("Degenerated_", (Standard_Boolean (*)(const TopoDS_Edge &)) &BRep_Tool::Degenerated, "Returns True if the edge is degenerated.", py::arg("E"));
	cls_BRep_Tool.def_static("Range_", (void (*)(const TopoDS_Edge &, Standard_Real &, Standard_Real &)) &BRep_Tool::Range, "Gets the range of the 3d curve.", py::arg("E"), py::arg("First"), py::arg("Last"));
	cls_BRep_Tool.def_static("Range_", (void (*)(const TopoDS_Edge &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, Standard_Real &, Standard_Real &)) &BRep_Tool::Range, "Gets the range of the edge on the pcurve on the surface.", py::arg("E"), py::arg("S"), py::arg("L"), py::arg("First"), py::arg("Last"));
	cls_BRep_Tool.def_static("Range_", (void (*)(const TopoDS_Edge &, const TopoDS_Face &, Standard_Real &, Standard_Real &)) &BRep_Tool::Range, "Gets the range of the edge on the pcurve on the face.", py::arg("E"), py::arg("F"), py::arg("First"), py::arg("Last"));
	cls_BRep_Tool.def_static("UVPoints_", (void (*)(const TopoDS_Edge &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, gp_Pnt2d &, gp_Pnt2d &)) &BRep_Tool::UVPoints, "Gets the UV locations of the extremities of the edge.", py::arg("E"), py::arg("S"), py::arg("L"), py::arg("PFirst"), py::arg("PLast"));
	cls_BRep_Tool.def_static("UVPoints_", (void (*)(const TopoDS_Edge &, const TopoDS_Face &, gp_Pnt2d &, gp_Pnt2d &)) &BRep_Tool::UVPoints, "Gets the UV locations of the extremities of the edge.", py::arg("E"), py::arg("F"), py::arg("PFirst"), py::arg("PLast"));
	cls_BRep_Tool.def_static("SetUVPoints_", (void (*)(const TopoDS_Edge &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const gp_Pnt2d &, const gp_Pnt2d &)) &BRep_Tool::SetUVPoints, "Sets the UV locations of the extremities of the edge.", py::arg("E"), py::arg("S"), py::arg("L"), py::arg("PFirst"), py::arg("PLast"));
	cls_BRep_Tool.def_static("SetUVPoints_", (void (*)(const TopoDS_Edge &, const TopoDS_Face &, const gp_Pnt2d &, const gp_Pnt2d &)) &BRep_Tool::SetUVPoints, "Sets the UV locations of the extremities of the edge.", py::arg("E"), py::arg("F"), py::arg("PFirst"), py::arg("PLast"));
	cls_BRep_Tool.def_static("HasContinuity_", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &)) &BRep_Tool::HasContinuity, "Returns True if the edge is on the surfaces of the two faces.", py::arg("E"), py::arg("F1"), py::arg("F2"));
	cls_BRep_Tool.def_static("Continuity_", (GeomAbs_Shape (*)(const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &)) &BRep_Tool::Continuity, "Returns the continuity.", py::arg("E"), py::arg("F1"), py::arg("F2"));
	cls_BRep_Tool.def_static("HasContinuity_", (Standard_Boolean (*)(const TopoDS_Edge &, const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const TopLoc_Location &)) &BRep_Tool::HasContinuity, "Returns True if the edge is on the surfaces.", py::arg("E"), py::arg("S1"), py::arg("S2"), py::arg("L1"), py::arg("L2"));
	cls_BRep_Tool.def_static("Continuity_", (GeomAbs_Shape (*)(const TopoDS_Edge &, const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const TopLoc_Location &)) &BRep_Tool::Continuity, "Returns the continuity.", py::arg("E"), py::arg("S1"), py::arg("S2"), py::arg("L1"), py::arg("L2"));
	cls_BRep_Tool.def_static("HasContinuity_", (Standard_Boolean (*)(const TopoDS_Edge &)) &BRep_Tool::HasContinuity, "Returns True if the edge has regularity on some two surfaces", py::arg("E"));
	cls_BRep_Tool.def_static("Pnt_", (gp_Pnt (*)(const TopoDS_Vertex &)) &BRep_Tool::Pnt, "Returns the 3d point.", py::arg("V"));
	cls_BRep_Tool.def_static("Tolerance_", (Standard_Real (*)(const TopoDS_Vertex &)) &BRep_Tool::Tolerance, "Returns the tolerance.", py::arg("V"));
	cls_BRep_Tool.def_static("Parameter_", (Standard_Real (*)(const TopoDS_Vertex &, const TopoDS_Edge &)) &BRep_Tool::Parameter, "Returns the parameter of <V> on <E>.", py::arg("V"), py::arg("E"));
	cls_BRep_Tool.def_static("Parameter_", (Standard_Real (*)(const TopoDS_Vertex &, const TopoDS_Edge &, const TopoDS_Face &)) &BRep_Tool::Parameter, "Returns the parameters of the vertex on the pcurve of the edge on the face.", py::arg("V"), py::arg("E"), py::arg("F"));
	cls_BRep_Tool.def_static("Parameter_", (Standard_Real (*)(const TopoDS_Vertex &, const TopoDS_Edge &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &)) &BRep_Tool::Parameter, "Returns the parameters of the vertex on the pcurve of the edge on the surface.", py::arg("V"), py::arg("E"), py::arg("S"), py::arg("L"));
	cls_BRep_Tool.def_static("Parameters_", (gp_Pnt2d (*)(const TopoDS_Vertex &, const TopoDS_Face &)) &BRep_Tool::Parameters, "Returns the parameters of the vertex on the face.", py::arg("V"), py::arg("F"));
	cls_BRep_Tool.def_static("MaxTolerance_", (Standard_Real (*)(const TopoDS_Shape &, const TopAbs_ShapeEnum)) &BRep_Tool::MaxTolerance, "None", py::arg("theShape"), py::arg("theSubShape"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRep_CurveRepresentation.hxx
	py::class_<BRep_CurveRepresentation, opencascade::handle<BRep_CurveRepresentation>, Standard_Transient> cls_BRep_CurveRepresentation(mod, "BRep_CurveRepresentation", "Root class for the curve representations. Contains a location.");
	cls_BRep_CurveRepresentation.def("IsCurve3D", (Standard_Boolean (BRep_CurveRepresentation::*)() const ) &BRep_CurveRepresentation::IsCurve3D, "A 3D curve representation.");
	cls_BRep_CurveRepresentation.def("IsCurveOnSurface", (Standard_Boolean (BRep_CurveRepresentation::*)() const ) &BRep_CurveRepresentation::IsCurveOnSurface, "A curve in the parametric space of a surface.");
	cls_BRep_CurveRepresentation.def("IsRegularity", (Standard_Boolean (BRep_CurveRepresentation::*)() const ) &BRep_CurveRepresentation::IsRegularity, "A continuity between two surfaces.");
	cls_BRep_CurveRepresentation.def("IsCurveOnClosedSurface", (Standard_Boolean (BRep_CurveRepresentation::*)() const ) &BRep_CurveRepresentation::IsCurveOnClosedSurface, "A curve with two parametric curves on the same surface.");
	cls_BRep_CurveRepresentation.def("IsCurveOnSurface", (Standard_Boolean (BRep_CurveRepresentation::*)(const opencascade::handle<Geom_Surface> &, const TopLoc_Location &) const ) &BRep_CurveRepresentation::IsCurveOnSurface, "Is it a curve in the parametric space of <S> with location <L>.", py::arg("S"), py::arg("L"));
	cls_BRep_CurveRepresentation.def("IsRegularity", (Standard_Boolean (BRep_CurveRepresentation::*)(const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const TopLoc_Location &) const ) &BRep_CurveRepresentation::IsRegularity, "Is it a regularity between <S1> and <S2> with location <L1> and <L2>.", py::arg("S1"), py::arg("S2"), py::arg("L1"), py::arg("L2"));
	cls_BRep_CurveRepresentation.def("IsPolygon3D", (Standard_Boolean (BRep_CurveRepresentation::*)() const ) &BRep_CurveRepresentation::IsPolygon3D, "A 3D polygon representation.");
	cls_BRep_CurveRepresentation.def("IsPolygonOnTriangulation", (Standard_Boolean (BRep_CurveRepresentation::*)() const ) &BRep_CurveRepresentation::IsPolygonOnTriangulation, "A representation by an array of nodes on a triangulation.");
	cls_BRep_CurveRepresentation.def("IsPolygonOnTriangulation", (Standard_Boolean (BRep_CurveRepresentation::*)(const opencascade::handle<Poly_Triangulation> &, const TopLoc_Location &) const ) &BRep_CurveRepresentation::IsPolygonOnTriangulation, "Is it a polygon in the definition of <T> with location <L>.", py::arg("T"), py::arg("L"));
	cls_BRep_CurveRepresentation.def("IsPolygonOnClosedTriangulation", (Standard_Boolean (BRep_CurveRepresentation::*)() const ) &BRep_CurveRepresentation::IsPolygonOnClosedTriangulation, "A representation by two arrays of nodes on a triangulation.");
	cls_BRep_CurveRepresentation.def("IsPolygonOnSurface", (Standard_Boolean (BRep_CurveRepresentation::*)() const ) &BRep_CurveRepresentation::IsPolygonOnSurface, "A polygon in the parametric space of a surface.");
	cls_BRep_CurveRepresentation.def("IsPolygonOnSurface", (Standard_Boolean (BRep_CurveRepresentation::*)(const opencascade::handle<Geom_Surface> &, const TopLoc_Location &) const ) &BRep_CurveRepresentation::IsPolygonOnSurface, "Is it a polygon in the parametric space of <S> with location <L>.", py::arg("S"), py::arg("L"));
	cls_BRep_CurveRepresentation.def("IsPolygonOnClosedSurface", (Standard_Boolean (BRep_CurveRepresentation::*)() const ) &BRep_CurveRepresentation::IsPolygonOnClosedSurface, "Two 2D polygon representations in the parametric space of a surface.");
	cls_BRep_CurveRepresentation.def("Location", (const TopLoc_Location & (BRep_CurveRepresentation::*)() const ) &BRep_CurveRepresentation::Location, "None");
	cls_BRep_CurveRepresentation.def("Location", (void (BRep_CurveRepresentation::*)(const TopLoc_Location &)) &BRep_CurveRepresentation::Location, "None", py::arg("L"));
	cls_BRep_CurveRepresentation.def("Curve3D", (const opencascade::handle<Geom_Curve> & (BRep_CurveRepresentation::*)() const ) &BRep_CurveRepresentation::Curve3D, "None");
	cls_BRep_CurveRepresentation.def("Curve3D", (void (BRep_CurveRepresentation::*)(const opencascade::handle<Geom_Curve> &)) &BRep_CurveRepresentation::Curve3D, "None", py::arg("C"));
	cls_BRep_CurveRepresentation.def("Surface", (const opencascade::handle<Geom_Surface> & (BRep_CurveRepresentation::*)() const ) &BRep_CurveRepresentation::Surface, "None");
	cls_BRep_CurveRepresentation.def("PCurve", (const opencascade::handle<Geom2d_Curve> & (BRep_CurveRepresentation::*)() const ) &BRep_CurveRepresentation::PCurve, "None");
	cls_BRep_CurveRepresentation.def("PCurve", (void (BRep_CurveRepresentation::*)(const opencascade::handle<Geom2d_Curve> &)) &BRep_CurveRepresentation::PCurve, "None", py::arg("C"));
	cls_BRep_CurveRepresentation.def("PCurve2", (const opencascade::handle<Geom2d_Curve> & (BRep_CurveRepresentation::*)() const ) &BRep_CurveRepresentation::PCurve2, "None");
	cls_BRep_CurveRepresentation.def("PCurve2", (void (BRep_CurveRepresentation::*)(const opencascade::handle<Geom2d_Curve> &)) &BRep_CurveRepresentation::PCurve2, "None", py::arg("C"));
	cls_BRep_CurveRepresentation.def("Polygon3D", (const opencascade::handle<Poly_Polygon3D> & (BRep_CurveRepresentation::*)() const ) &BRep_CurveRepresentation::Polygon3D, "None");
	cls_BRep_CurveRepresentation.def("Polygon3D", (void (BRep_CurveRepresentation::*)(const opencascade::handle<Poly_Polygon3D> &)) &BRep_CurveRepresentation::Polygon3D, "None", py::arg("P"));
	cls_BRep_CurveRepresentation.def("Polygon", (const opencascade::handle<Poly_Polygon2D> & (BRep_CurveRepresentation::*)() const ) &BRep_CurveRepresentation::Polygon, "None");
	cls_BRep_CurveRepresentation.def("Polygon", (void (BRep_CurveRepresentation::*)(const opencascade::handle<Poly_Polygon2D> &)) &BRep_CurveRepresentation::Polygon, "None", py::arg("P"));
	cls_BRep_CurveRepresentation.def("Polygon2", (const opencascade::handle<Poly_Polygon2D> & (BRep_CurveRepresentation::*)() const ) &BRep_CurveRepresentation::Polygon2, "None");
	cls_BRep_CurveRepresentation.def("Polygon2", (void (BRep_CurveRepresentation::*)(const opencascade::handle<Poly_Polygon2D> &)) &BRep_CurveRepresentation::Polygon2, "None", py::arg("P"));
	cls_BRep_CurveRepresentation.def("Triangulation", (const opencascade::handle<Poly_Triangulation> & (BRep_CurveRepresentation::*)() const ) &BRep_CurveRepresentation::Triangulation, "None");
	cls_BRep_CurveRepresentation.def("PolygonOnTriangulation", (const opencascade::handle<Poly_PolygonOnTriangulation> & (BRep_CurveRepresentation::*)() const ) &BRep_CurveRepresentation::PolygonOnTriangulation, "None");
	cls_BRep_CurveRepresentation.def("PolygonOnTriangulation", (void (BRep_CurveRepresentation::*)(const opencascade::handle<Poly_PolygonOnTriangulation> &)) &BRep_CurveRepresentation::PolygonOnTriangulation, "None", py::arg("P"));
	cls_BRep_CurveRepresentation.def("PolygonOnTriangulation2", (const opencascade::handle<Poly_PolygonOnTriangulation> & (BRep_CurveRepresentation::*)() const ) &BRep_CurveRepresentation::PolygonOnTriangulation2, "None");
	cls_BRep_CurveRepresentation.def("PolygonOnTriangulation2", (void (BRep_CurveRepresentation::*)(const opencascade::handle<Poly_PolygonOnTriangulation> &)) &BRep_CurveRepresentation::PolygonOnTriangulation2, "None", py::arg("P2"));
	cls_BRep_CurveRepresentation.def("Surface2", (const opencascade::handle<Geom_Surface> & (BRep_CurveRepresentation::*)() const ) &BRep_CurveRepresentation::Surface2, "None");
	cls_BRep_CurveRepresentation.def("Location2", (const TopLoc_Location & (BRep_CurveRepresentation::*)() const ) &BRep_CurveRepresentation::Location2, "None");
	cls_BRep_CurveRepresentation.def("Continuity", (const GeomAbs_Shape & (BRep_CurveRepresentation::*)() const ) &BRep_CurveRepresentation::Continuity, "None");
	cls_BRep_CurveRepresentation.def("Continuity", (void (BRep_CurveRepresentation::*)(const GeomAbs_Shape)) &BRep_CurveRepresentation::Continuity, "None", py::arg("C"));
	cls_BRep_CurveRepresentation.def("Copy", (opencascade::handle<BRep_CurveRepresentation> (BRep_CurveRepresentation::*)() const ) &BRep_CurveRepresentation::Copy, "Return a copy of this representation.");
	cls_BRep_CurveRepresentation.def_static("get_type_name_", (const char * (*)()) &BRep_CurveRepresentation::get_type_name, "None");
	cls_BRep_CurveRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRep_CurveRepresentation::get_type_descriptor, "None");
	cls_BRep_CurveRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRep_CurveRepresentation::*)() const ) &BRep_CurveRepresentation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRep_GCurve.hxx
	py::class_<BRep_GCurve, opencascade::handle<BRep_GCurve>, BRep_CurveRepresentation> cls_BRep_GCurve(mod, "BRep_GCurve", "Root class for the geometric curves representation. Contains a range. Contains a first and a last parameter.");
	cls_BRep_GCurve.def("SetRange", (void (BRep_GCurve::*)(const Standard_Real, const Standard_Real)) &BRep_GCurve::SetRange, "None", py::arg("First"), py::arg("Last"));
	cls_BRep_GCurve.def("Range", (void (BRep_GCurve::*)(Standard_Real &, Standard_Real &) const ) &BRep_GCurve::Range, "None", py::arg("First"), py::arg("Last"));
	cls_BRep_GCurve.def("First", (Standard_Real (BRep_GCurve::*)() const ) &BRep_GCurve::First, "None");
	cls_BRep_GCurve.def("Last", (Standard_Real (BRep_GCurve::*)() const ) &BRep_GCurve::Last, "None");
	cls_BRep_GCurve.def("First", (void (BRep_GCurve::*)(const Standard_Real)) &BRep_GCurve::First, "None", py::arg("F"));
	cls_BRep_GCurve.def("Last", (void (BRep_GCurve::*)(const Standard_Real)) &BRep_GCurve::Last, "None", py::arg("L"));
	cls_BRep_GCurve.def("D0", (void (BRep_GCurve::*)(const Standard_Real, gp_Pnt &) const ) &BRep_GCurve::D0, "Computes the point at parameter U.", py::arg("U"), py::arg("P"));
	cls_BRep_GCurve.def("Update", (void (BRep_GCurve::*)()) &BRep_GCurve::Update, "Recomputes any derived data after a modification. This is called when the range is modified.");
	cls_BRep_GCurve.def_static("get_type_name_", (const char * (*)()) &BRep_GCurve::get_type_name, "None");
	cls_BRep_GCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRep_GCurve::get_type_descriptor, "None");
	cls_BRep_GCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRep_GCurve::*)() const ) &BRep_GCurve::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRep_Curve3D.hxx
	py::class_<BRep_Curve3D, opencascade::handle<BRep_Curve3D>, BRep_GCurve> cls_BRep_Curve3D(mod, "BRep_Curve3D", "Representation of a curve by a 3D curve.");
	cls_BRep_Curve3D.def(py::init<const opencascade::handle<Geom_Curve> &, const TopLoc_Location &>(), py::arg("C"), py::arg("L"));
	cls_BRep_Curve3D.def("D0", (void (BRep_Curve3D::*)(const Standard_Real, gp_Pnt &) const ) &BRep_Curve3D::D0, "Computes the point at parameter U.", py::arg("U"), py::arg("P"));
	cls_BRep_Curve3D.def("IsCurve3D", (Standard_Boolean (BRep_Curve3D::*)() const ) &BRep_Curve3D::IsCurve3D, "Returns True.");
	cls_BRep_Curve3D.def("Curve3D", (const opencascade::handle<Geom_Curve> & (BRep_Curve3D::*)() const ) &BRep_Curve3D::Curve3D, "None");
	cls_BRep_Curve3D.def("Curve3D", (void (BRep_Curve3D::*)(const opencascade::handle<Geom_Curve> &)) &BRep_Curve3D::Curve3D, "None", py::arg("C"));
	cls_BRep_Curve3D.def("Copy", (opencascade::handle<BRep_CurveRepresentation> (BRep_Curve3D::*)() const ) &BRep_Curve3D::Copy, "Return a copy of this representation.");
	cls_BRep_Curve3D.def_static("get_type_name_", (const char * (*)()) &BRep_Curve3D::get_type_name, "None");
	cls_BRep_Curve3D.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRep_Curve3D::get_type_descriptor, "None");
	cls_BRep_Curve3D.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRep_Curve3D::*)() const ) &BRep_Curve3D::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRep_CurveOn2Surfaces.hxx
	py::class_<BRep_CurveOn2Surfaces, opencascade::handle<BRep_CurveOn2Surfaces>, BRep_CurveRepresentation> cls_BRep_CurveOn2Surfaces(mod, "BRep_CurveOn2Surfaces", "Defines a continuity between two surfaces.");
	cls_BRep_CurveOn2Surfaces.def(py::init<const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const TopLoc_Location &, const GeomAbs_Shape>(), py::arg("S1"), py::arg("S2"), py::arg("L1"), py::arg("L2"), py::arg("C"));
	cls_BRep_CurveOn2Surfaces.def("IsRegularity", (Standard_Boolean (BRep_CurveOn2Surfaces::*)() const ) &BRep_CurveOn2Surfaces::IsRegularity, "Returns True.");
	cls_BRep_CurveOn2Surfaces.def("IsRegularity", (Standard_Boolean (BRep_CurveOn2Surfaces::*)(const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const TopLoc_Location &) const ) &BRep_CurveOn2Surfaces::IsRegularity, "A curve on two surfaces (continuity).", py::arg("S1"), py::arg("S2"), py::arg("L1"), py::arg("L2"));
	cls_BRep_CurveOn2Surfaces.def("D0", (void (BRep_CurveOn2Surfaces::*)(const Standard_Real, gp_Pnt &) const ) &BRep_CurveOn2Surfaces::D0, "Raises an error.", py::arg("U"), py::arg("P"));
	cls_BRep_CurveOn2Surfaces.def("Surface", (const opencascade::handle<Geom_Surface> & (BRep_CurveOn2Surfaces::*)() const ) &BRep_CurveOn2Surfaces::Surface, "None");
	cls_BRep_CurveOn2Surfaces.def("Surface2", (const opencascade::handle<Geom_Surface> & (BRep_CurveOn2Surfaces::*)() const ) &BRep_CurveOn2Surfaces::Surface2, "None");
	cls_BRep_CurveOn2Surfaces.def("Location2", (const TopLoc_Location & (BRep_CurveOn2Surfaces::*)() const ) &BRep_CurveOn2Surfaces::Location2, "None");
	cls_BRep_CurveOn2Surfaces.def("Continuity", (const GeomAbs_Shape & (BRep_CurveOn2Surfaces::*)() const ) &BRep_CurveOn2Surfaces::Continuity, "None");
	cls_BRep_CurveOn2Surfaces.def("Continuity", (void (BRep_CurveOn2Surfaces::*)(const GeomAbs_Shape)) &BRep_CurveOn2Surfaces::Continuity, "None", py::arg("C"));
	cls_BRep_CurveOn2Surfaces.def("Copy", (opencascade::handle<BRep_CurveRepresentation> (BRep_CurveOn2Surfaces::*)() const ) &BRep_CurveOn2Surfaces::Copy, "Return a copy of this representation.");
	cls_BRep_CurveOn2Surfaces.def_static("get_type_name_", (const char * (*)()) &BRep_CurveOn2Surfaces::get_type_name, "None");
	cls_BRep_CurveOn2Surfaces.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRep_CurveOn2Surfaces::get_type_descriptor, "None");
	cls_BRep_CurveOn2Surfaces.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRep_CurveOn2Surfaces::*)() const ) &BRep_CurveOn2Surfaces::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRep_CurveOnSurface.hxx
	py::class_<BRep_CurveOnSurface, opencascade::handle<BRep_CurveOnSurface>, BRep_GCurve> cls_BRep_CurveOnSurface(mod, "BRep_CurveOnSurface", "Representation of a curve by a curve in the parametric space of a surface.");
	cls_BRep_CurveOnSurface.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &>(), py::arg("PC"), py::arg("S"), py::arg("L"));
	cls_BRep_CurveOnSurface.def("SetUVPoints", (void (BRep_CurveOnSurface::*)(const gp_Pnt2d &, const gp_Pnt2d &)) &BRep_CurveOnSurface::SetUVPoints, "None", py::arg("P1"), py::arg("P2"));
	cls_BRep_CurveOnSurface.def("UVPoints", (void (BRep_CurveOnSurface::*)(gp_Pnt2d &, gp_Pnt2d &) const ) &BRep_CurveOnSurface::UVPoints, "None", py::arg("P1"), py::arg("P2"));
	cls_BRep_CurveOnSurface.def("D0", (void (BRep_CurveOnSurface::*)(const Standard_Real, gp_Pnt &) const ) &BRep_CurveOnSurface::D0, "Computes the point at parameter U.", py::arg("U"), py::arg("P"));
	cls_BRep_CurveOnSurface.def("IsCurveOnSurface", (Standard_Boolean (BRep_CurveOnSurface::*)() const ) &BRep_CurveOnSurface::IsCurveOnSurface, "Returns True.");
	cls_BRep_CurveOnSurface.def("IsCurveOnSurface", (Standard_Boolean (BRep_CurveOnSurface::*)(const opencascade::handle<Geom_Surface> &, const TopLoc_Location &) const ) &BRep_CurveOnSurface::IsCurveOnSurface, "A curve in the parametric space of a surface.", py::arg("S"), py::arg("L"));
	cls_BRep_CurveOnSurface.def("Surface", (const opencascade::handle<Geom_Surface> & (BRep_CurveOnSurface::*)() const ) &BRep_CurveOnSurface::Surface, "None");
	cls_BRep_CurveOnSurface.def("PCurve", (const opencascade::handle<Geom2d_Curve> & (BRep_CurveOnSurface::*)() const ) &BRep_CurveOnSurface::PCurve, "None");
	cls_BRep_CurveOnSurface.def("PCurve", (void (BRep_CurveOnSurface::*)(const opencascade::handle<Geom2d_Curve> &)) &BRep_CurveOnSurface::PCurve, "None", py::arg("C"));
	cls_BRep_CurveOnSurface.def("Copy", (opencascade::handle<BRep_CurveRepresentation> (BRep_CurveOnSurface::*)() const ) &BRep_CurveOnSurface::Copy, "Return a copy of this representation.");
	cls_BRep_CurveOnSurface.def("Update", (void (BRep_CurveOnSurface::*)()) &BRep_CurveOnSurface::Update, "Recomputes any derived data after a modification. This is called when the range is modified.");
	cls_BRep_CurveOnSurface.def_static("get_type_name_", (const char * (*)()) &BRep_CurveOnSurface::get_type_name, "None");
	cls_BRep_CurveOnSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRep_CurveOnSurface::get_type_descriptor, "None");
	cls_BRep_CurveOnSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRep_CurveOnSurface::*)() const ) &BRep_CurveOnSurface::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRep_CurveOnClosedSurface.hxx
	py::class_<BRep_CurveOnClosedSurface, opencascade::handle<BRep_CurveOnClosedSurface>, BRep_CurveOnSurface> cls_BRep_CurveOnClosedSurface(mod, "BRep_CurveOnClosedSurface", "Representation of a curve by two pcurves on a closed surface.");
	cls_BRep_CurveOnClosedSurface.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const GeomAbs_Shape>(), py::arg("PC1"), py::arg("PC2"), py::arg("S"), py::arg("L"), py::arg("C"));
	cls_BRep_CurveOnClosedSurface.def("SetUVPoints2", (void (BRep_CurveOnClosedSurface::*)(const gp_Pnt2d &, const gp_Pnt2d &)) &BRep_CurveOnClosedSurface::SetUVPoints2, "None", py::arg("P1"), py::arg("P2"));
	cls_BRep_CurveOnClosedSurface.def("UVPoints2", (void (BRep_CurveOnClosedSurface::*)(gp_Pnt2d &, gp_Pnt2d &) const ) &BRep_CurveOnClosedSurface::UVPoints2, "None", py::arg("P1"), py::arg("P2"));
	cls_BRep_CurveOnClosedSurface.def("IsCurveOnClosedSurface", (Standard_Boolean (BRep_CurveOnClosedSurface::*)() const ) &BRep_CurveOnClosedSurface::IsCurveOnClosedSurface, "Returns True.");
	cls_BRep_CurveOnClosedSurface.def("IsRegularity", (Standard_Boolean (BRep_CurveOnClosedSurface::*)() const ) &BRep_CurveOnClosedSurface::IsRegularity, "Returns True");
	cls_BRep_CurveOnClosedSurface.def("IsRegularity", (Standard_Boolean (BRep_CurveOnClosedSurface::*)(const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const TopLoc_Location &) const ) &BRep_CurveOnClosedSurface::IsRegularity, "A curve on two surfaces (continuity).", py::arg("S1"), py::arg("S2"), py::arg("L1"), py::arg("L2"));
	cls_BRep_CurveOnClosedSurface.def("PCurve2", (const opencascade::handle<Geom2d_Curve> & (BRep_CurveOnClosedSurface::*)() const ) &BRep_CurveOnClosedSurface::PCurve2, "None");
	cls_BRep_CurveOnClosedSurface.def("Surface2", (const opencascade::handle<Geom_Surface> & (BRep_CurveOnClosedSurface::*)() const ) &BRep_CurveOnClosedSurface::Surface2, "Returns Surface()");
	cls_BRep_CurveOnClosedSurface.def("Location2", (const TopLoc_Location & (BRep_CurveOnClosedSurface::*)() const ) &BRep_CurveOnClosedSurface::Location2, "Returns Location()");
	cls_BRep_CurveOnClosedSurface.def("Continuity", (const GeomAbs_Shape & (BRep_CurveOnClosedSurface::*)() const ) &BRep_CurveOnClosedSurface::Continuity, "None");
	cls_BRep_CurveOnClosedSurface.def("Continuity", (void (BRep_CurveOnClosedSurface::*)(const GeomAbs_Shape)) &BRep_CurveOnClosedSurface::Continuity, "None", py::arg("C"));
	cls_BRep_CurveOnClosedSurface.def("PCurve2", (void (BRep_CurveOnClosedSurface::*)(const opencascade::handle<Geom2d_Curve> &)) &BRep_CurveOnClosedSurface::PCurve2, "None", py::arg("C"));
	cls_BRep_CurveOnClosedSurface.def("Copy", (opencascade::handle<BRep_CurveRepresentation> (BRep_CurveOnClosedSurface::*)() const ) &BRep_CurveOnClosedSurface::Copy, "Return a copy of this representation.");
	cls_BRep_CurveOnClosedSurface.def("Update", (void (BRep_CurveOnClosedSurface::*)()) &BRep_CurveOnClosedSurface::Update, "Recomputes any derived data after a modification. This is called when the range is modified.");
	cls_BRep_CurveOnClosedSurface.def_static("get_type_name_", (const char * (*)()) &BRep_CurveOnClosedSurface::get_type_name, "None");
	cls_BRep_CurveOnClosedSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRep_CurveOnClosedSurface::get_type_descriptor, "None");
	cls_BRep_CurveOnClosedSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRep_CurveOnClosedSurface::*)() const ) &BRep_CurveOnClosedSurface::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRep_PointOnCurve.hxx
	py::class_<BRep_PointOnCurve, opencascade::handle<BRep_PointOnCurve>, BRep_PointRepresentation> cls_BRep_PointOnCurve(mod, "BRep_PointOnCurve", "Representation by a parameter on a 3D curve.");
	cls_BRep_PointOnCurve.def(py::init<const Standard_Real, const opencascade::handle<Geom_Curve> &, const TopLoc_Location &>(), py::arg("P"), py::arg("C"), py::arg("L"));
	cls_BRep_PointOnCurve.def("IsPointOnCurve", (Standard_Boolean (BRep_PointOnCurve::*)() const ) &BRep_PointOnCurve::IsPointOnCurve, "Returns True");
	cls_BRep_PointOnCurve.def("IsPointOnCurve", (Standard_Boolean (BRep_PointOnCurve::*)(const opencascade::handle<Geom_Curve> &, const TopLoc_Location &) const ) &BRep_PointOnCurve::IsPointOnCurve, "None", py::arg("C"), py::arg("L"));
	cls_BRep_PointOnCurve.def("Curve", (const opencascade::handle<Geom_Curve> & (BRep_PointOnCurve::*)() const ) &BRep_PointOnCurve::Curve, "None");
	cls_BRep_PointOnCurve.def("Curve", (void (BRep_PointOnCurve::*)(const opencascade::handle<Geom_Curve> &)) &BRep_PointOnCurve::Curve, "None", py::arg("C"));
	cls_BRep_PointOnCurve.def_static("get_type_name_", (const char * (*)()) &BRep_PointOnCurve::get_type_name, "None");
	cls_BRep_PointOnCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRep_PointOnCurve::get_type_descriptor, "None");
	cls_BRep_PointOnCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRep_PointOnCurve::*)() const ) &BRep_PointOnCurve::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRep_PointsOnSurface.hxx
	py::class_<BRep_PointsOnSurface, opencascade::handle<BRep_PointsOnSurface>, BRep_PointRepresentation> cls_BRep_PointsOnSurface(mod, "BRep_PointsOnSurface", "Root for points on surface.");
	cls_BRep_PointsOnSurface.def("Surface", (const opencascade::handle<Geom_Surface> & (BRep_PointsOnSurface::*)() const ) &BRep_PointsOnSurface::Surface, "None");
	cls_BRep_PointsOnSurface.def("Surface", (void (BRep_PointsOnSurface::*)(const opencascade::handle<Geom_Surface> &)) &BRep_PointsOnSurface::Surface, "None", py::arg("S"));
	cls_BRep_PointsOnSurface.def_static("get_type_name_", (const char * (*)()) &BRep_PointsOnSurface::get_type_name, "None");
	cls_BRep_PointsOnSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRep_PointsOnSurface::get_type_descriptor, "None");
	cls_BRep_PointsOnSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRep_PointsOnSurface::*)() const ) &BRep_PointsOnSurface::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRep_PointOnCurveOnSurface.hxx
	py::class_<BRep_PointOnCurveOnSurface, opencascade::handle<BRep_PointOnCurveOnSurface>, BRep_PointsOnSurface> cls_BRep_PointOnCurveOnSurface(mod, "BRep_PointOnCurveOnSurface", "Representation by a parameter on a curve on a surface.");
	cls_BRep_PointOnCurveOnSurface.def(py::init<const Standard_Real, const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &>(), py::arg("P"), py::arg("C"), py::arg("S"), py::arg("L"));
	cls_BRep_PointOnCurveOnSurface.def("IsPointOnCurveOnSurface", (Standard_Boolean (BRep_PointOnCurveOnSurface::*)() const ) &BRep_PointOnCurveOnSurface::IsPointOnCurveOnSurface, "Returns True");
	cls_BRep_PointOnCurveOnSurface.def("IsPointOnCurveOnSurface", (Standard_Boolean (BRep_PointOnCurveOnSurface::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &) const ) &BRep_PointOnCurveOnSurface::IsPointOnCurveOnSurface, "None", py::arg("PC"), py::arg("S"), py::arg("L"));
	cls_BRep_PointOnCurveOnSurface.def("PCurve", (const opencascade::handle<Geom2d_Curve> & (BRep_PointOnCurveOnSurface::*)() const ) &BRep_PointOnCurveOnSurface::PCurve, "None");
	cls_BRep_PointOnCurveOnSurface.def("PCurve", (void (BRep_PointOnCurveOnSurface::*)(const opencascade::handle<Geom2d_Curve> &)) &BRep_PointOnCurveOnSurface::PCurve, "None", py::arg("C"));
	cls_BRep_PointOnCurveOnSurface.def_static("get_type_name_", (const char * (*)()) &BRep_PointOnCurveOnSurface::get_type_name, "None");
	cls_BRep_PointOnCurveOnSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRep_PointOnCurveOnSurface::get_type_descriptor, "None");
	cls_BRep_PointOnCurveOnSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRep_PointOnCurveOnSurface::*)() const ) &BRep_PointOnCurveOnSurface::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRep_PointOnSurface.hxx
	py::class_<BRep_PointOnSurface, opencascade::handle<BRep_PointOnSurface>, BRep_PointsOnSurface> cls_BRep_PointOnSurface(mod, "BRep_PointOnSurface", "Representation by two parameters on a surface.");
	cls_BRep_PointOnSurface.def(py::init<const Standard_Real, const Standard_Real, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &>(), py::arg("P1"), py::arg("P2"), py::arg("S"), py::arg("L"));
	cls_BRep_PointOnSurface.def("IsPointOnSurface", (Standard_Boolean (BRep_PointOnSurface::*)() const ) &BRep_PointOnSurface::IsPointOnSurface, "None");
	cls_BRep_PointOnSurface.def("IsPointOnSurface", (Standard_Boolean (BRep_PointOnSurface::*)(const opencascade::handle<Geom_Surface> &, const TopLoc_Location &) const ) &BRep_PointOnSurface::IsPointOnSurface, "None", py::arg("S"), py::arg("L"));
	cls_BRep_PointOnSurface.def("Parameter2", (Standard_Real (BRep_PointOnSurface::*)() const ) &BRep_PointOnSurface::Parameter2, "None");
	cls_BRep_PointOnSurface.def("Parameter2", (void (BRep_PointOnSurface::*)(const Standard_Real)) &BRep_PointOnSurface::Parameter2, "None", py::arg("P"));
	cls_BRep_PointOnSurface.def_static("get_type_name_", (const char * (*)()) &BRep_PointOnSurface::get_type_name, "None");
	cls_BRep_PointOnSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRep_PointOnSurface::get_type_descriptor, "None");
	cls_BRep_PointOnSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRep_PointOnSurface::*)() const ) &BRep_PointOnSurface::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRep_Polygon3D.hxx
	py::class_<BRep_Polygon3D, opencascade::handle<BRep_Polygon3D>, BRep_CurveRepresentation> cls_BRep_Polygon3D(mod, "BRep_Polygon3D", "Representation by a 3D polygon.");
	cls_BRep_Polygon3D.def(py::init<const opencascade::handle<Poly_Polygon3D> &, const TopLoc_Location &>(), py::arg("P"), py::arg("L"));
	cls_BRep_Polygon3D.def("IsPolygon3D", (Standard_Boolean (BRep_Polygon3D::*)() const ) &BRep_Polygon3D::IsPolygon3D, "Returns True.");
	cls_BRep_Polygon3D.def("Polygon3D", (const opencascade::handle<Poly_Polygon3D> & (BRep_Polygon3D::*)() const ) &BRep_Polygon3D::Polygon3D, "None");
	cls_BRep_Polygon3D.def("Polygon3D", (void (BRep_Polygon3D::*)(const opencascade::handle<Poly_Polygon3D> &)) &BRep_Polygon3D::Polygon3D, "None", py::arg("P"));
	cls_BRep_Polygon3D.def("Copy", (opencascade::handle<BRep_CurveRepresentation> (BRep_Polygon3D::*)() const ) &BRep_Polygon3D::Copy, "Return a copy of this representation.");
	cls_BRep_Polygon3D.def_static("get_type_name_", (const char * (*)()) &BRep_Polygon3D::get_type_name, "None");
	cls_BRep_Polygon3D.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRep_Polygon3D::get_type_descriptor, "None");
	cls_BRep_Polygon3D.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRep_Polygon3D::*)() const ) &BRep_Polygon3D::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRep_PolygonOnSurface.hxx
	py::class_<BRep_PolygonOnSurface, opencascade::handle<BRep_PolygonOnSurface>, BRep_CurveRepresentation> cls_BRep_PolygonOnSurface(mod, "BRep_PolygonOnSurface", "Representation of a 2D polygon in the parametric space of a surface.");
	cls_BRep_PolygonOnSurface.def(py::init<const opencascade::handle<Poly_Polygon2D> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &>(), py::arg("P"), py::arg("S"), py::arg("L"));
	cls_BRep_PolygonOnSurface.def("IsPolygonOnSurface", (Standard_Boolean (BRep_PolygonOnSurface::*)() const ) &BRep_PolygonOnSurface::IsPolygonOnSurface, "A 2D polygon representation in the parametric space of a surface.");
	cls_BRep_PolygonOnSurface.def("IsPolygonOnSurface", (Standard_Boolean (BRep_PolygonOnSurface::*)(const opencascade::handle<Geom_Surface> &, const TopLoc_Location &) const ) &BRep_PolygonOnSurface::IsPolygonOnSurface, "A 2D polygon representation in the parametric space of a surface.", py::arg("S"), py::arg("L"));
	cls_BRep_PolygonOnSurface.def("Surface", (const opencascade::handle<Geom_Surface> & (BRep_PolygonOnSurface::*)() const ) &BRep_PolygonOnSurface::Surface, "None");
	cls_BRep_PolygonOnSurface.def("Polygon", (const opencascade::handle<Poly_Polygon2D> & (BRep_PolygonOnSurface::*)() const ) &BRep_PolygonOnSurface::Polygon, "None");
	cls_BRep_PolygonOnSurface.def("Polygon", (void (BRep_PolygonOnSurface::*)(const opencascade::handle<Poly_Polygon2D> &)) &BRep_PolygonOnSurface::Polygon, "None", py::arg("P"));
	cls_BRep_PolygonOnSurface.def("Copy", (opencascade::handle<BRep_CurveRepresentation> (BRep_PolygonOnSurface::*)() const ) &BRep_PolygonOnSurface::Copy, "Return a copy of this representation.");
	cls_BRep_PolygonOnSurface.def_static("get_type_name_", (const char * (*)()) &BRep_PolygonOnSurface::get_type_name, "None");
	cls_BRep_PolygonOnSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRep_PolygonOnSurface::get_type_descriptor, "None");
	cls_BRep_PolygonOnSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRep_PolygonOnSurface::*)() const ) &BRep_PolygonOnSurface::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRep_PolygonOnClosedSurface.hxx
	py::class_<BRep_PolygonOnClosedSurface, opencascade::handle<BRep_PolygonOnClosedSurface>, BRep_PolygonOnSurface> cls_BRep_PolygonOnClosedSurface(mod, "BRep_PolygonOnClosedSurface", "Representation by two 2d polygons in the parametric space of a surface.");
	cls_BRep_PolygonOnClosedSurface.def(py::init<const opencascade::handle<Poly_Polygon2D> &, const opencascade::handle<Poly_Polygon2D> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &>(), py::arg("P1"), py::arg("P2"), py::arg("S"), py::arg("L"));
	cls_BRep_PolygonOnClosedSurface.def("IsPolygonOnClosedSurface", (Standard_Boolean (BRep_PolygonOnClosedSurface::*)() const ) &BRep_PolygonOnClosedSurface::IsPolygonOnClosedSurface, "returns True.");
	cls_BRep_PolygonOnClosedSurface.def("Polygon2", (const opencascade::handle<Poly_Polygon2D> & (BRep_PolygonOnClosedSurface::*)() const ) &BRep_PolygonOnClosedSurface::Polygon2, "None");
	cls_BRep_PolygonOnClosedSurface.def("Polygon2", (void (BRep_PolygonOnClosedSurface::*)(const opencascade::handle<Poly_Polygon2D> &)) &BRep_PolygonOnClosedSurface::Polygon2, "None", py::arg("P"));
	cls_BRep_PolygonOnClosedSurface.def("Copy", (opencascade::handle<BRep_CurveRepresentation> (BRep_PolygonOnClosedSurface::*)() const ) &BRep_PolygonOnClosedSurface::Copy, "Return a copy of this representation.");
	cls_BRep_PolygonOnClosedSurface.def_static("get_type_name_", (const char * (*)()) &BRep_PolygonOnClosedSurface::get_type_name, "None");
	cls_BRep_PolygonOnClosedSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRep_PolygonOnClosedSurface::get_type_descriptor, "None");
	cls_BRep_PolygonOnClosedSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRep_PolygonOnClosedSurface::*)() const ) &BRep_PolygonOnClosedSurface::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRep_PolygonOnTriangulation.hxx
	py::class_<BRep_PolygonOnTriangulation, opencascade::handle<BRep_PolygonOnTriangulation>, BRep_CurveRepresentation> cls_BRep_PolygonOnTriangulation(mod, "BRep_PolygonOnTriangulation", "A representation by an array of nodes on a triangulation.");
	cls_BRep_PolygonOnTriangulation.def(py::init<const opencascade::handle<Poly_PolygonOnTriangulation> &, const opencascade::handle<Poly_Triangulation> &, const TopLoc_Location &>(), py::arg("P"), py::arg("T"), py::arg("L"));
	cls_BRep_PolygonOnTriangulation.def("IsPolygonOnTriangulation", (Standard_Boolean (BRep_PolygonOnTriangulation::*)() const ) &BRep_PolygonOnTriangulation::IsPolygonOnTriangulation, "returns True.");
	cls_BRep_PolygonOnTriangulation.def("IsPolygonOnTriangulation", (Standard_Boolean (BRep_PolygonOnTriangulation::*)(const opencascade::handle<Poly_Triangulation> &, const TopLoc_Location &) const ) &BRep_PolygonOnTriangulation::IsPolygonOnTriangulation, "Is it a polygon in the definition of <T> with location <L>.", py::arg("T"), py::arg("L"));
	cls_BRep_PolygonOnTriangulation.def("PolygonOnTriangulation", (void (BRep_PolygonOnTriangulation::*)(const opencascade::handle<Poly_PolygonOnTriangulation> &)) &BRep_PolygonOnTriangulation::PolygonOnTriangulation, "returns True.", py::arg("P"));
	cls_BRep_PolygonOnTriangulation.def("Triangulation", (const opencascade::handle<Poly_Triangulation> & (BRep_PolygonOnTriangulation::*)() const ) &BRep_PolygonOnTriangulation::Triangulation, "None");
	cls_BRep_PolygonOnTriangulation.def("PolygonOnTriangulation", (const opencascade::handle<Poly_PolygonOnTriangulation> & (BRep_PolygonOnTriangulation::*)() const ) &BRep_PolygonOnTriangulation::PolygonOnTriangulation, "None");
	cls_BRep_PolygonOnTriangulation.def("Copy", (opencascade::handle<BRep_CurveRepresentation> (BRep_PolygonOnTriangulation::*)() const ) &BRep_PolygonOnTriangulation::Copy, "Return a copy of this representation.");
	cls_BRep_PolygonOnTriangulation.def_static("get_type_name_", (const char * (*)()) &BRep_PolygonOnTriangulation::get_type_name, "None");
	cls_BRep_PolygonOnTriangulation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRep_PolygonOnTriangulation::get_type_descriptor, "None");
	cls_BRep_PolygonOnTriangulation.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRep_PolygonOnTriangulation::*)() const ) &BRep_PolygonOnTriangulation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRep_PolygonOnClosedTriangulation.hxx
	py::class_<BRep_PolygonOnClosedTriangulation, opencascade::handle<BRep_PolygonOnClosedTriangulation>, BRep_PolygonOnTriangulation> cls_BRep_PolygonOnClosedTriangulation(mod, "BRep_PolygonOnClosedTriangulation", "A representation by two arrays of nodes on a triangulation.");
	cls_BRep_PolygonOnClosedTriangulation.def(py::init<const opencascade::handle<Poly_PolygonOnTriangulation> &, const opencascade::handle<Poly_PolygonOnTriangulation> &, const opencascade::handle<Poly_Triangulation> &, const TopLoc_Location &>(), py::arg("P1"), py::arg("P2"), py::arg("Tr"), py::arg("L"));
	cls_BRep_PolygonOnClosedTriangulation.def("IsPolygonOnClosedTriangulation", (Standard_Boolean (BRep_PolygonOnClosedTriangulation::*)() const ) &BRep_PolygonOnClosedTriangulation::IsPolygonOnClosedTriangulation, "Returns True.");
	cls_BRep_PolygonOnClosedTriangulation.def("PolygonOnTriangulation2", (void (BRep_PolygonOnClosedTriangulation::*)(const opencascade::handle<Poly_PolygonOnTriangulation> &)) &BRep_PolygonOnClosedTriangulation::PolygonOnTriangulation2, "None", py::arg("P2"));
	cls_BRep_PolygonOnClosedTriangulation.def("PolygonOnTriangulation2", (const opencascade::handle<Poly_PolygonOnTriangulation> & (BRep_PolygonOnClosedTriangulation::*)() const ) &BRep_PolygonOnClosedTriangulation::PolygonOnTriangulation2, "None");
	cls_BRep_PolygonOnClosedTriangulation.def("Copy", (opencascade::handle<BRep_CurveRepresentation> (BRep_PolygonOnClosedTriangulation::*)() const ) &BRep_PolygonOnClosedTriangulation::Copy, "Return a copy of this representation.");
	cls_BRep_PolygonOnClosedTriangulation.def_static("get_type_name_", (const char * (*)()) &BRep_PolygonOnClosedTriangulation::get_type_name, "None");
	cls_BRep_PolygonOnClosedTriangulation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRep_PolygonOnClosedTriangulation::get_type_descriptor, "None");
	cls_BRep_PolygonOnClosedTriangulation.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRep_PolygonOnClosedTriangulation::*)() const ) &BRep_PolygonOnClosedTriangulation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRep_TEdge.hxx
	py::class_<BRep_TEdge, opencascade::handle<BRep_TEdge>, TopoDS_TEdge> cls_BRep_TEdge(mod, "BRep_TEdge", "The TEdge from BRep is inherited from the TEdge from TopoDS. It contains the geometric data.");
	cls_BRep_TEdge.def(py::init<>());
	cls_BRep_TEdge.def("Tolerance", (Standard_Real (BRep_TEdge::*)() const ) &BRep_TEdge::Tolerance, "None");
	cls_BRep_TEdge.def("Tolerance", (void (BRep_TEdge::*)(const Standard_Real)) &BRep_TEdge::Tolerance, "None", py::arg("T"));
	cls_BRep_TEdge.def("UpdateTolerance", (void (BRep_TEdge::*)(const Standard_Real)) &BRep_TEdge::UpdateTolerance, "Sets the tolerance to the max of <T> and the current tolerance.", py::arg("T"));
	cls_BRep_TEdge.def("SameParameter", (Standard_Boolean (BRep_TEdge::*)() const ) &BRep_TEdge::SameParameter, "None");
	cls_BRep_TEdge.def("SameParameter", (void (BRep_TEdge::*)(const Standard_Boolean)) &BRep_TEdge::SameParameter, "None", py::arg("S"));
	cls_BRep_TEdge.def("SameRange", (Standard_Boolean (BRep_TEdge::*)() const ) &BRep_TEdge::SameRange, "None");
	cls_BRep_TEdge.def("SameRange", (void (BRep_TEdge::*)(const Standard_Boolean)) &BRep_TEdge::SameRange, "None", py::arg("S"));
	cls_BRep_TEdge.def("Degenerated", (Standard_Boolean (BRep_TEdge::*)() const ) &BRep_TEdge::Degenerated, "None");
	cls_BRep_TEdge.def("Degenerated", (void (BRep_TEdge::*)(const Standard_Boolean)) &BRep_TEdge::Degenerated, "None", py::arg("S"));
	cls_BRep_TEdge.def("Curves", (const BRep_ListOfCurveRepresentation & (BRep_TEdge::*)() const ) &BRep_TEdge::Curves, "None");
	cls_BRep_TEdge.def("ChangeCurves", (BRep_ListOfCurveRepresentation & (BRep_TEdge::*)()) &BRep_TEdge::ChangeCurves, "None");
	cls_BRep_TEdge.def("EmptyCopy", (opencascade::handle<TopoDS_TShape> (BRep_TEdge::*)() const ) &BRep_TEdge::EmptyCopy, "Returns a copy of the TShape with no sub-shapes.");
	cls_BRep_TEdge.def_static("get_type_name_", (const char * (*)()) &BRep_TEdge::get_type_name, "None");
	cls_BRep_TEdge.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRep_TEdge::get_type_descriptor, "None");
	cls_BRep_TEdge.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRep_TEdge::*)() const ) &BRep_TEdge::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_List.hxx
	py::class_<BRep_ListOfPointRepresentation, std::unique_ptr<BRep_ListOfPointRepresentation, Deleter<BRep_ListOfPointRepresentation>>, NCollection_BaseList> cls_BRep_ListOfPointRepresentation(mod, "BRep_ListOfPointRepresentation", "Purpose: Simple list to link items together keeping the first and the last one. Inherits BaseList, adding the data item to each node.");
	cls_BRep_ListOfPointRepresentation.def(py::init<>());
	cls_BRep_ListOfPointRepresentation.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_BRep_ListOfPointRepresentation.def(py::init([] (const BRep_ListOfPointRepresentation &other) {return new BRep_ListOfPointRepresentation(other);}), "Copy constructor", py::arg("other"));
	cls_BRep_ListOfPointRepresentation.def("begin", (BRep_ListOfPointRepresentation::iterator (BRep_ListOfPointRepresentation::*)() const ) &BRep_ListOfPointRepresentation::begin, "Returns an iterator pointing to the first element in the list.");
	cls_BRep_ListOfPointRepresentation.def("end", (BRep_ListOfPointRepresentation::iterator (BRep_ListOfPointRepresentation::*)() const ) &BRep_ListOfPointRepresentation::end, "Returns an iterator referring to the past-the-end element in the list.");
	cls_BRep_ListOfPointRepresentation.def("cbegin", (BRep_ListOfPointRepresentation::const_iterator (BRep_ListOfPointRepresentation::*)() const ) &BRep_ListOfPointRepresentation::cbegin, "Returns a const iterator pointing to the first element in the list.");
	cls_BRep_ListOfPointRepresentation.def("cend", (BRep_ListOfPointRepresentation::const_iterator (BRep_ListOfPointRepresentation::*)() const ) &BRep_ListOfPointRepresentation::cend, "Returns a const iterator referring to the past-the-end element in the list.");
	cls_BRep_ListOfPointRepresentation.def("Size", (Standard_Integer (BRep_ListOfPointRepresentation::*)() const ) &BRep_ListOfPointRepresentation::Size, "Size - Number of items");
	cls_BRep_ListOfPointRepresentation.def("Assign", (BRep_ListOfPointRepresentation & (BRep_ListOfPointRepresentation::*)(const BRep_ListOfPointRepresentation &)) &BRep_ListOfPointRepresentation::Assign, "Replace this list by the items of another list (theOther parameter). This method does not change the internal allocator.", py::arg("theOther"));
	cls_BRep_ListOfPointRepresentation.def("assign", (BRep_ListOfPointRepresentation & (BRep_ListOfPointRepresentation::*)(const BRep_ListOfPointRepresentation &)) &BRep_ListOfPointRepresentation::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_BRep_ListOfPointRepresentation.def("Clear", [](BRep_ListOfPointRepresentation &self) -> void { return self.Clear(); });
	cls_BRep_ListOfPointRepresentation.def("Clear", (void (BRep_ListOfPointRepresentation::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BRep_ListOfPointRepresentation::Clear, "Clear this list", py::arg("theAllocator"));
	cls_BRep_ListOfPointRepresentation.def("First", (const opencascade::handle<BRep_PointRepresentation> & (BRep_ListOfPointRepresentation::*)() const ) &BRep_ListOfPointRepresentation::First, "First item");
	cls_BRep_ListOfPointRepresentation.def("First", (opencascade::handle<BRep_PointRepresentation> & (BRep_ListOfPointRepresentation::*)()) &BRep_ListOfPointRepresentation::First, "First item (non-const)");
	cls_BRep_ListOfPointRepresentation.def("Last", (const opencascade::handle<BRep_PointRepresentation> & (BRep_ListOfPointRepresentation::*)() const ) &BRep_ListOfPointRepresentation::Last, "Last item");
	cls_BRep_ListOfPointRepresentation.def("Last", (opencascade::handle<BRep_PointRepresentation> & (BRep_ListOfPointRepresentation::*)()) &BRep_ListOfPointRepresentation::Last, "Last item (non-const)");
	cls_BRep_ListOfPointRepresentation.def("Append", (opencascade::handle<BRep_PointRepresentation> & (BRep_ListOfPointRepresentation::*)(const opencascade::handle<BRep_PointRepresentation> &)) &BRep_ListOfPointRepresentation::Append, "Append one item at the end", py::arg("theItem"));
	cls_BRep_ListOfPointRepresentation.def("Append", (void (BRep_ListOfPointRepresentation::*)(const opencascade::handle<BRep_PointRepresentation> &, BRep_ListOfPointRepresentation::Iterator &)) &BRep_ListOfPointRepresentation::Append, "Append one item at the end and output iterator pointing at the appended item", py::arg("theItem"), py::arg("theIter"));
	cls_BRep_ListOfPointRepresentation.def("Append", (void (BRep_ListOfPointRepresentation::*)(BRep_ListOfPointRepresentation &)) &BRep_ListOfPointRepresentation::Append, "Append another list at the end", py::arg("theOther"));
	cls_BRep_ListOfPointRepresentation.def("Prepend", (opencascade::handle<BRep_PointRepresentation> & (BRep_ListOfPointRepresentation::*)(const opencascade::handle<BRep_PointRepresentation> &)) &BRep_ListOfPointRepresentation::Prepend, "Prepend one item at the beginning", py::arg("theItem"));
	cls_BRep_ListOfPointRepresentation.def("Prepend", (void (BRep_ListOfPointRepresentation::*)(BRep_ListOfPointRepresentation &)) &BRep_ListOfPointRepresentation::Prepend, "Prepend another list at the beginning", py::arg("theOther"));
	cls_BRep_ListOfPointRepresentation.def("RemoveFirst", (void (BRep_ListOfPointRepresentation::*)()) &BRep_ListOfPointRepresentation::RemoveFirst, "RemoveFirst item");
	cls_BRep_ListOfPointRepresentation.def("Remove", (void (BRep_ListOfPointRepresentation::*)(BRep_ListOfPointRepresentation::Iterator &)) &BRep_ListOfPointRepresentation::Remove, "Remove item pointed by iterator theIter; theIter is then set to the next item", py::arg("theIter"));
	cls_BRep_ListOfPointRepresentation.def("InsertBefore", (opencascade::handle<BRep_PointRepresentation> & (BRep_ListOfPointRepresentation::*)(const opencascade::handle<BRep_PointRepresentation> &, BRep_ListOfPointRepresentation::Iterator &)) &BRep_ListOfPointRepresentation::InsertBefore, "InsertBefore", py::arg("theItem"), py::arg("theIter"));
	cls_BRep_ListOfPointRepresentation.def("InsertBefore", (void (BRep_ListOfPointRepresentation::*)(BRep_ListOfPointRepresentation &, BRep_ListOfPointRepresentation::Iterator &)) &BRep_ListOfPointRepresentation::InsertBefore, "InsertBefore", py::arg("theOther"), py::arg("theIter"));
	cls_BRep_ListOfPointRepresentation.def("InsertAfter", (opencascade::handle<BRep_PointRepresentation> & (BRep_ListOfPointRepresentation::*)(const opencascade::handle<BRep_PointRepresentation> &, BRep_ListOfPointRepresentation::Iterator &)) &BRep_ListOfPointRepresentation::InsertAfter, "InsertAfter", py::arg("theItem"), py::arg("theIter"));
	cls_BRep_ListOfPointRepresentation.def("InsertAfter", (void (BRep_ListOfPointRepresentation::*)(BRep_ListOfPointRepresentation &, BRep_ListOfPointRepresentation::Iterator &)) &BRep_ListOfPointRepresentation::InsertAfter, "InsertAfter", py::arg("theOther"), py::arg("theIter"));
	cls_BRep_ListOfPointRepresentation.def("Reverse", (void (BRep_ListOfPointRepresentation::*)()) &BRep_ListOfPointRepresentation::Reverse, "Reverse the list");
	cls_BRep_ListOfPointRepresentation.def("__iter__", [](const BRep_ListOfPointRepresentation &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_TListIterator.hxx
	py::class_<BRep_ListIteratorOfListOfPointRepresentation, std::unique_ptr<BRep_ListIteratorOfListOfPointRepresentation, Deleter<BRep_ListIteratorOfListOfPointRepresentation>>> cls_BRep_ListIteratorOfListOfPointRepresentation(mod, "BRep_ListIteratorOfListOfPointRepresentation", "Purpose: This Iterator class iterates on BaseList of TListNode and is instantiated in List/Set/Queue/Stack Remark: TListIterator is internal class");
	cls_BRep_ListIteratorOfListOfPointRepresentation.def(py::init<>());
	cls_BRep_ListIteratorOfListOfPointRepresentation.def(py::init<const NCollection_BaseList &>(), py::arg("theList"));
	cls_BRep_ListIteratorOfListOfPointRepresentation.def("More", (Standard_Boolean (BRep_ListIteratorOfListOfPointRepresentation::*)() const ) &BRep_ListIteratorOfListOfPointRepresentation::More, "Check end");
	cls_BRep_ListIteratorOfListOfPointRepresentation.def("Next", (void (BRep_ListIteratorOfListOfPointRepresentation::*)()) &BRep_ListIteratorOfListOfPointRepresentation::Next, "Make step");
	cls_BRep_ListIteratorOfListOfPointRepresentation.def("Value", (const opencascade::handle<BRep_PointRepresentation> & (BRep_ListIteratorOfListOfPointRepresentation::*)() const ) &BRep_ListIteratorOfListOfPointRepresentation::Value, "Constant Value access");
	cls_BRep_ListIteratorOfListOfPointRepresentation.def("Value", (opencascade::handle<BRep_PointRepresentation> & (BRep_ListIteratorOfListOfPointRepresentation::*)()) &BRep_ListIteratorOfListOfPointRepresentation::Value, "Non-const Value access");
	cls_BRep_ListIteratorOfListOfPointRepresentation.def("ChangeValue", (opencascade::handle<BRep_PointRepresentation> & (BRep_ListIteratorOfListOfPointRepresentation::*)() const ) &BRep_ListIteratorOfListOfPointRepresentation::ChangeValue, "Non-const Value access");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_List.hxx
	py::class_<BRep_ListOfCurveRepresentation, std::unique_ptr<BRep_ListOfCurveRepresentation, Deleter<BRep_ListOfCurveRepresentation>>, NCollection_BaseList> cls_BRep_ListOfCurveRepresentation(mod, "BRep_ListOfCurveRepresentation", "Purpose: Simple list to link items together keeping the first and the last one. Inherits BaseList, adding the data item to each node.");
	cls_BRep_ListOfCurveRepresentation.def(py::init<>());
	cls_BRep_ListOfCurveRepresentation.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_BRep_ListOfCurveRepresentation.def(py::init([] (const BRep_ListOfCurveRepresentation &other) {return new BRep_ListOfCurveRepresentation(other);}), "Copy constructor", py::arg("other"));
	cls_BRep_ListOfCurveRepresentation.def("begin", (BRep_ListOfCurveRepresentation::iterator (BRep_ListOfCurveRepresentation::*)() const ) &BRep_ListOfCurveRepresentation::begin, "Returns an iterator pointing to the first element in the list.");
	cls_BRep_ListOfCurveRepresentation.def("end", (BRep_ListOfCurveRepresentation::iterator (BRep_ListOfCurveRepresentation::*)() const ) &BRep_ListOfCurveRepresentation::end, "Returns an iterator referring to the past-the-end element in the list.");
	cls_BRep_ListOfCurveRepresentation.def("cbegin", (BRep_ListOfCurveRepresentation::const_iterator (BRep_ListOfCurveRepresentation::*)() const ) &BRep_ListOfCurveRepresentation::cbegin, "Returns a const iterator pointing to the first element in the list.");
	cls_BRep_ListOfCurveRepresentation.def("cend", (BRep_ListOfCurveRepresentation::const_iterator (BRep_ListOfCurveRepresentation::*)() const ) &BRep_ListOfCurveRepresentation::cend, "Returns a const iterator referring to the past-the-end element in the list.");
	cls_BRep_ListOfCurveRepresentation.def("Size", (Standard_Integer (BRep_ListOfCurveRepresentation::*)() const ) &BRep_ListOfCurveRepresentation::Size, "Size - Number of items");
	cls_BRep_ListOfCurveRepresentation.def("Assign", (BRep_ListOfCurveRepresentation & (BRep_ListOfCurveRepresentation::*)(const BRep_ListOfCurveRepresentation &)) &BRep_ListOfCurveRepresentation::Assign, "Replace this list by the items of another list (theOther parameter). This method does not change the internal allocator.", py::arg("theOther"));
	cls_BRep_ListOfCurveRepresentation.def("assign", (BRep_ListOfCurveRepresentation & (BRep_ListOfCurveRepresentation::*)(const BRep_ListOfCurveRepresentation &)) &BRep_ListOfCurveRepresentation::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_BRep_ListOfCurveRepresentation.def("Clear", [](BRep_ListOfCurveRepresentation &self) -> void { return self.Clear(); });
	cls_BRep_ListOfCurveRepresentation.def("Clear", (void (BRep_ListOfCurveRepresentation::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BRep_ListOfCurveRepresentation::Clear, "Clear this list", py::arg("theAllocator"));
	cls_BRep_ListOfCurveRepresentation.def("First", (const opencascade::handle<BRep_CurveRepresentation> & (BRep_ListOfCurveRepresentation::*)() const ) &BRep_ListOfCurveRepresentation::First, "First item");
	cls_BRep_ListOfCurveRepresentation.def("First", (opencascade::handle<BRep_CurveRepresentation> & (BRep_ListOfCurveRepresentation::*)()) &BRep_ListOfCurveRepresentation::First, "First item (non-const)");
	cls_BRep_ListOfCurveRepresentation.def("Last", (const opencascade::handle<BRep_CurveRepresentation> & (BRep_ListOfCurveRepresentation::*)() const ) &BRep_ListOfCurveRepresentation::Last, "Last item");
	cls_BRep_ListOfCurveRepresentation.def("Last", (opencascade::handle<BRep_CurveRepresentation> & (BRep_ListOfCurveRepresentation::*)()) &BRep_ListOfCurveRepresentation::Last, "Last item (non-const)");
	cls_BRep_ListOfCurveRepresentation.def("Append", (opencascade::handle<BRep_CurveRepresentation> & (BRep_ListOfCurveRepresentation::*)(const opencascade::handle<BRep_CurveRepresentation> &)) &BRep_ListOfCurveRepresentation::Append, "Append one item at the end", py::arg("theItem"));
	cls_BRep_ListOfCurveRepresentation.def("Append", (void (BRep_ListOfCurveRepresentation::*)(const opencascade::handle<BRep_CurveRepresentation> &, BRep_ListOfCurveRepresentation::Iterator &)) &BRep_ListOfCurveRepresentation::Append, "Append one item at the end and output iterator pointing at the appended item", py::arg("theItem"), py::arg("theIter"));
	cls_BRep_ListOfCurveRepresentation.def("Append", (void (BRep_ListOfCurveRepresentation::*)(BRep_ListOfCurveRepresentation &)) &BRep_ListOfCurveRepresentation::Append, "Append another list at the end", py::arg("theOther"));
	cls_BRep_ListOfCurveRepresentation.def("Prepend", (opencascade::handle<BRep_CurveRepresentation> & (BRep_ListOfCurveRepresentation::*)(const opencascade::handle<BRep_CurveRepresentation> &)) &BRep_ListOfCurveRepresentation::Prepend, "Prepend one item at the beginning", py::arg("theItem"));
	cls_BRep_ListOfCurveRepresentation.def("Prepend", (void (BRep_ListOfCurveRepresentation::*)(BRep_ListOfCurveRepresentation &)) &BRep_ListOfCurveRepresentation::Prepend, "Prepend another list at the beginning", py::arg("theOther"));
	cls_BRep_ListOfCurveRepresentation.def("RemoveFirst", (void (BRep_ListOfCurveRepresentation::*)()) &BRep_ListOfCurveRepresentation::RemoveFirst, "RemoveFirst item");
	cls_BRep_ListOfCurveRepresentation.def("Remove", (void (BRep_ListOfCurveRepresentation::*)(BRep_ListOfCurveRepresentation::Iterator &)) &BRep_ListOfCurveRepresentation::Remove, "Remove item pointed by iterator theIter; theIter is then set to the next item", py::arg("theIter"));
	cls_BRep_ListOfCurveRepresentation.def("InsertBefore", (opencascade::handle<BRep_CurveRepresentation> & (BRep_ListOfCurveRepresentation::*)(const opencascade::handle<BRep_CurveRepresentation> &, BRep_ListOfCurveRepresentation::Iterator &)) &BRep_ListOfCurveRepresentation::InsertBefore, "InsertBefore", py::arg("theItem"), py::arg("theIter"));
	cls_BRep_ListOfCurveRepresentation.def("InsertBefore", (void (BRep_ListOfCurveRepresentation::*)(BRep_ListOfCurveRepresentation &, BRep_ListOfCurveRepresentation::Iterator &)) &BRep_ListOfCurveRepresentation::InsertBefore, "InsertBefore", py::arg("theOther"), py::arg("theIter"));
	cls_BRep_ListOfCurveRepresentation.def("InsertAfter", (opencascade::handle<BRep_CurveRepresentation> & (BRep_ListOfCurveRepresentation::*)(const opencascade::handle<BRep_CurveRepresentation> &, BRep_ListOfCurveRepresentation::Iterator &)) &BRep_ListOfCurveRepresentation::InsertAfter, "InsertAfter", py::arg("theItem"), py::arg("theIter"));
	cls_BRep_ListOfCurveRepresentation.def("InsertAfter", (void (BRep_ListOfCurveRepresentation::*)(BRep_ListOfCurveRepresentation &, BRep_ListOfCurveRepresentation::Iterator &)) &BRep_ListOfCurveRepresentation::InsertAfter, "InsertAfter", py::arg("theOther"), py::arg("theIter"));
	cls_BRep_ListOfCurveRepresentation.def("Reverse", (void (BRep_ListOfCurveRepresentation::*)()) &BRep_ListOfCurveRepresentation::Reverse, "Reverse the list");
	cls_BRep_ListOfCurveRepresentation.def("__iter__", [](const BRep_ListOfCurveRepresentation &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_TListIterator.hxx
	py::class_<BRep_ListIteratorOfListOfCurveRepresentation, std::unique_ptr<BRep_ListIteratorOfListOfCurveRepresentation, Deleter<BRep_ListIteratorOfListOfCurveRepresentation>>> cls_BRep_ListIteratorOfListOfCurveRepresentation(mod, "BRep_ListIteratorOfListOfCurveRepresentation", "Purpose: This Iterator class iterates on BaseList of TListNode and is instantiated in List/Set/Queue/Stack Remark: TListIterator is internal class");
	cls_BRep_ListIteratorOfListOfCurveRepresentation.def(py::init<>());
	cls_BRep_ListIteratorOfListOfCurveRepresentation.def(py::init<const NCollection_BaseList &>(), py::arg("theList"));
	cls_BRep_ListIteratorOfListOfCurveRepresentation.def("More", (Standard_Boolean (BRep_ListIteratorOfListOfCurveRepresentation::*)() const ) &BRep_ListIteratorOfListOfCurveRepresentation::More, "Check end");
	cls_BRep_ListIteratorOfListOfCurveRepresentation.def("Next", (void (BRep_ListIteratorOfListOfCurveRepresentation::*)()) &BRep_ListIteratorOfListOfCurveRepresentation::Next, "Make step");
	cls_BRep_ListIteratorOfListOfCurveRepresentation.def("Value", (const opencascade::handle<BRep_CurveRepresentation> & (BRep_ListIteratorOfListOfCurveRepresentation::*)() const ) &BRep_ListIteratorOfListOfCurveRepresentation::Value, "Constant Value access");
	cls_BRep_ListIteratorOfListOfCurveRepresentation.def("Value", (opencascade::handle<BRep_CurveRepresentation> & (BRep_ListIteratorOfListOfCurveRepresentation::*)()) &BRep_ListIteratorOfListOfCurveRepresentation::Value, "Non-const Value access");
	cls_BRep_ListIteratorOfListOfCurveRepresentation.def("ChangeValue", (opencascade::handle<BRep_CurveRepresentation> & (BRep_ListIteratorOfListOfCurveRepresentation::*)() const ) &BRep_ListIteratorOfListOfCurveRepresentation::ChangeValue, "Non-const Value access");


}