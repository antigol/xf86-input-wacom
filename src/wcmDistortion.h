/*
 * Copyright 1995-2003 by Frederic Lepied, France. <Lepied@XFree86.org>
 * Copyright 2002-2007 by Ping Cheng, Wacom. <pingc@wacom.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef __XF86_WCMDISTORTION_H
#define __XF86_WCMDISTORTION_H

/* Solve Ax = b where A is square with an LU factorization */
int wcmSolveLS(int n, const double* A, const double* b, double* x);

/* Solve min ||Ax - b|| where A is dimention nxm */
int wcmLeastSquares(int n, int m, const double* A, const double* b, double* x);

/* minimize || Ax - b || in x
 * under constraint Cx = e
 *
 * A : n x m Matrix
 * b : n Vector
 * C : p x m Matrix
 * e : p Vector
 */
int wcmLeastSquaresWithConstraint(int m, int n, int p,
								  const double* A, const double* b,
								  const double* C, const double* e,
								  double* x);


int distortionCorrectionComputePolynomial(double d, double p, double a, double h, double* poly);

#endif // __XF86_WCMDISTORTION_H
