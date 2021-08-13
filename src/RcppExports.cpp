// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// is_assign
bool is_assign(std::vector<std::string> code);
RcppExport SEXP _AstToAst_is_assign(SEXP codeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector<std::string> >::type code(codeSEXP);
    rcpp_result_gen = Rcpp::wrap(is_assign(code));
    return rcpp_result_gen;
END_RCPP
}
// stor_var
std::string stor_var(std::vector<std::string> code);
RcppExport SEXP _AstToAst_stor_var(SEXP codeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector<std::string> >::type code(codeSEXP);
    rcpp_result_gen = Rcpp::wrap(stor_var(code));
    return rcpp_result_gen;
END_RCPP
}
// find_var_at_rhs
std::vector<std::string> find_var_at_rhs(std::vector<std::string> code);
RcppExport SEXP _AstToAst_find_var_at_rhs(SEXP codeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector<std::string> >::type code(codeSEXP);
    rcpp_result_gen = Rcpp::wrap(find_var_at_rhs(code));
    return rcpp_result_gen;
END_RCPP
}

RcppExport SEXP run_testthat_tests(SEXP);

static const R_CallMethodDef CallEntries[] = {
    {"_AstToAst_is_assign", (DL_FUNC) &_AstToAst_is_assign, 1},
    {"_AstToAst_stor_var", (DL_FUNC) &_AstToAst_stor_var, 1},
    {"_AstToAst_find_var_at_rhs", (DL_FUNC) &_AstToAst_find_var_at_rhs, 1},
    {"run_testthat_tests", (DL_FUNC) &run_testthat_tests, 1},
    {NULL, NULL, 0}
};

RcppExport void R_init_AstToAst(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}